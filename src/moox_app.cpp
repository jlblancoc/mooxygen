/* +---------------------------------------------------------------------------+
   |                          The Mooxygen project                             |
   |                    https://github.com/jlblancoc/mooxygen                  |
   |                                                                           |
   | Copyright (C) 2009-2010 Jose Luis Blanco <joseluisblancoc at gmail.com >  |
   |                                                                           |
   |    This software was written by Jose Luis Blanco,                         |
   |      University of Malaga (Spain).                                        |
   |                                                                           |
   |  This file is part of the Mooxygen project.                               |
   |                                                                           |
   |     Mooxygen is free software: you can redistribute it and/or modify      |
   |     it under the terms of the GNU General Public License as published by  |
   |     the Free Software Foundation, either version 3 of the License, or     |
   |     (at your option) any later version.                                   |
   |                                                                           |
   |   Mooxygen is distributed in the hope that it will be useful,             |
   |     but WITHOUT ANY WARRANTY; without even the implied warranty of        |
   |     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
   |     GNU General Public License for more details.                          |
   |                                                                           |
   |     You should have received a copy of the GNU General Public License     |
   |     along with Mooxygen.  If not, see <http://www.gnu.org/licenses/>.     |
   |                                                                           |
   +---------------------------------------------------------------------------+ */

#include "moox_app.h"

using namespace std;
using namespace mooxygen;



bool recursiveDirExplorer(
	const string dir,
	set<string> &lstDirs,
	TApplication::TSourcesList &lstFiles,
	const StrSet &validExts )
{
	TDirListing dirlist;
	if (!mooxygen::dirExplorer(dir, dirlist))
	{
		cerr << "Error scanning directory " << dir << endl;
		return false;
	}

	for (TDirListing::const_iterator it=dirlist.begin();it!=dirlist.end();it++)
	{
		if (it->isDir)
		{
			if (it->name[0]!='.')
			{
				// Recursive:
				if (!recursiveDirExplorer(it->wholePath,lstDirs,lstFiles,validExts)) return false;
			}
		}
		else
		{
			// It's a file:
			size_t p=it->wholePath.find_last_of(".");
			if (p!=string::npos && p>0)
			{
				const string ext = it->wholePath.substr(p+1);
				if (validExts.count(ext))
				{
					lstFiles.push_back(*it);
					lstDirs.insert(dir);
				}
			}
		}
	}
	return true;
}

bool TApplication::scanForSourceFiles()
{
	m_root_path = convertBackslashes( trim(opts.get("INPUT_PATH")) );

	if (!pathExists(m_root_path))
	{
		cerr << "Project root path does not exist: " << m_root_path << endl;
		return false;
	}

    StrSet validExts;
    validExts.insert("cpp");
    validExts.insert("cxx");
    validExts.insert("h");
    validExts.insert("hpp");

	return recursiveDirExplorer( m_root_path,lstDirectories,lstSourceFiles,validExts);
}

bool TApplication::scanForMissionFiles()
{
	m_root_path_missions = convertBackslashes( trim(opts.get("MISSIONS_PATH")) );

    if (m_root_path_missions.empty())
        return true; // None to explore.

	if (!pathExists(m_root_path_missions))
	{
		cerr << "Mission path does not exist: " << m_root_path_missions << endl;
		return false;
	}

    StrSet validExts;
    validExts.insert("MOOS");
    validExts.insert("moos");
    validExts.insert("Moos");

	return recursiveDirExplorer( m_root_path_missions,lstMissionDirectories,lstMissionFiles,validExts);
}

bool TApplication::parseSourceFiles()
{
#define MOOS_URL "http://www.robots.ox.ac.uk/~mobile/MOOS/wiki/pmwiki.php"

	// Set default main page before parsing user files: 
	const string  PROJECT_NAME = opts.get("PROJECT");
	mainPage = string("This is the overview of all the <a href=\"" MOOS_URL "\" >MOOS</a> modules and variables for the project "
			"<i>")+ PROJECT_NAME + string("</i>.<br>\n"
			"Use the tabs above to navigate among the documentation.<br>\n");

	// Parse:	
	for(TSourcesList::const_iterator i=lstSourceFiles.begin();i!=lstSourceFiles.end();++i)
		if (!parseOneSourceFile(*i))
			return false;
	return true;
}

bool TApplication::parseOneSourceFile( const TSourcesList::value_type fil )
{
	const string relPath = getRelativePath( fil.wholePath ) ;
	cout << rightPad(string("Parsing ")+relPath,70);

	ifstream fi;
	fi.open(fil.wholePath.c_str());
	if (!fi.is_open())
	{
		cerr << "ERROR" << endl << "  Cannot open the file" << endl;
		return false;
	}

	bool in_comment=false;
	bool in_comment_block=false; // We should wait for "*/"
	list<string>        comment_block;
	list<list<string> > comment_blocks;
	list<string>		autodetectedPublishVars;

	size_t  nLin=0;
	while (!fi.fail() && !fi.eof())
	{
		string lin;
		std::getline(fi,lin);
		nLin++;
		lin=trim(lin);
		if (lin.empty()) continue;

		// Process line --------------------------------------
		bool do_process_block = false;
		if (!in_comment)
		{
			size_t p;
			// Look for the begining of a comment block:
			if ( (p=lin.find("/**"))!=string::npos ||
				 (p=lin.find("/*!"))!=string::npos )
			{
				string s = trim(lin.substr(p+3));

				in_comment_block = true;
				in_comment=true;
				comment_block.clear();

				// Check if the comment ends in the same line, like in:
				/**  ajskajsk */

				if ((p=s.find("*/"))!=string::npos)
				{
					s = s.substr(0,p);
					in_comment_block = false;
					in_comment=false;
				}
				comment_block.push_back( s + std::string(" ") );
			}
			else
			{
				// Look for the start of a series of "//!" or "///" comment lines:
				if ( (p=lin.find("///"))!=string::npos ||
					 (p=lin.find("//!"))!=string::npos )
				{
					string s = trim(lin.substr(p+3));

					in_comment_block = false;
					in_comment=true;
					comment_block.clear();
					comment_block.push_back( s );
				}
			}
			
		}

		{
			// Also, try to autodetect common MOOS C++ code:
			//   m_Comms.Notify("VAR_NAME"
			//
			size_t p;
			if (string::npos!= (p=upperCase(lin).find("M_COMMS.NOTIFY(")))
			{
				// After the ["M_COMMS.NOTIFY("] there must be a '"', a string, a '"', then ',', ignoring whitespaces.
				size_t p2=p+strlen("M_COMMS.NOTIFY(");
				bool ok=false;
				while (p2<lin.size())
				{
					if (lin[p2]=='\"') {ok=true; break;}
					if (lin[p2]!=' ' && lin[p2]!='\t') break;
					p2++;
				}
				if (ok)
				{
					const size_t idx_start = p2+1;
					p2++;
					ok=false;
					while (p2<lin.size())
					{
						if (lin[p2]=='\"') {ok=true; break;}
						p2++;
					}
					if (ok && p2>(idx_start+1))
					{
						const size_t idx_end = p2-1;

						// Final check: next must come a ",":
						p2++;
						ok=false;
						while (p2<lin.size())
						{
							if (lin[p2]==',') {ok=true; break;}
							if (lin[p2]!=' ' && lin[p2]!='\t') break;
							p2++;
						}
						if (ok)
						{
							const std::string varNam = upperCase( lin.substr(idx_start,idx_end-idx_start+1) );
							autodetectedPublishVars.push_back(varNam);
						}
					}
				}
			}
		}

		{
			// We were in a comment block ... Is it ended now?
			if (in_comment_block)
			{
				// We are in a "/** ..."
				//  wait for "*/"
				size_t p;
				if ((p=lin.find("*/"))!=string::npos)
				{
					string s=trim( lin.substr(0,p) );
					s = s.substr(0, s.find_first_not_of("* \t") );

					s=trim(s);
					if (!s.empty())
						comment_block.push_back(s);

					do_process_block = true;
					in_comment_block = false;
					in_comment = false;
				}
				else
				{
					// Add line:
					string s=trim(lin);
					size_t p = s.find_first_not_of("* \t");
					if (p!=string::npos)
					{
						s = s.substr(p);
						comment_block.push_back(s + std::string(" "));
					}
				}
			}
			else
			{
				// End of a sequence of comment lines?
				if (lin.find("///")==string::npos &&
					lin.find("//!")==string::npos )
				{
					do_process_block = true;
					in_comment = false;
				}
				else
				{
					// Continue with this line:
					size_t p;
					if ( (p=lin.find("///"))!=string::npos ||
						 (p=lin.find("//!"))!=string::npos )
					{
						comment_block.push_back( trim(lin.substr(p+3)) );
					}
				}
			}

			// Do we have a block?
			if (do_process_block)
			{
				//std::copy(comment_block.begin(),comment_block.end(),ostream_iterator<string>(cout,"\n"));
				comment_blocks.push_back(comment_block);
				comment_block.clear();
			}
		}
	}

	// Process all now in a row:
	processCommentBlocks(fil, comment_blocks,autodetectedPublishVars);

	cout << "OK" << endl;
	return true;
}

string TApplication::getRelativePath(const string &f) const
{
	size_t p = f.find(m_root_path);
	if (p!=0) return f; // shouldn't ???

	return f.substr(m_root_path.size()+1);
}

string TApplication::getMissionRelativePath(const string &f) const
{
	size_t p = f.find(m_root_path_missions);
	if (p!=0) return f; // shouldn't ???
	return f.substr(m_root_path_missions.size()+1);
}




void TApplication::processCommentBlocks(
	const TSourcesList::value_type fil,
	const list<list<string> > &lins,
	const list<string> &autodetectedPublishVars )
{
	// Try to determine the name of the module from
	//  1) The command "@moos_module_name", or
	//  2) The last part of the path
	// --------------------------------------------------------
 	string mod_name = "UNNAMED";
	{
		size_t last_p = fil.wholePath.find_last_of("/");
		if (last_p!=string::npos && last_p>0)
		{
			size_t prelast_p = fil.wholePath.find_last_of("/",last_p-1);
			if (prelast_p==string::npos)
				mod_name = fil.wholePath.substr(last_p-1);
			else
				mod_name = fil.wholePath.substr(prelast_p+1,last_p-prelast_p-1);
		}
	}

	bool anyCommand = false;


	// Look for Mooxygen commands:
	// --------------------------------------------------------
	for (list<list<string> >::const_iterator i=lins.begin();i!=lins.end();++i)
	{
		const list<string> &lins = *i;
		string 	*waitingLongDesc = NULL;

		for (list<string>::const_iterator l=lins.begin();l!=lins.end();++l)
		{
			const string &s = *l;
			size_t p;

			if ((p= lowerCase(s).find("@moos_module_name"))!=string::npos)
			{
				anyCommand=true;

				waitingLongDesc = NULL;
			}
			else if ((p=lowerCase(s).find("@moos_module"))!=string::npos)
			{
				anyCommand=true;
				string rest = trim(s.substr(p+strlen("@moos_module")));
				mods[mod_name].short_desc = rest;
				waitingLongDesc = &mods[mod_name].desc;
			}
			else if ((p=lowerCase(s).find("@moos_todo"))!=string::npos)
			{
				anyCommand=true;
				string todo = trim(s.substr(p+strlen("@moos_todo")));
				//mods[mod_name].TODO = todo;
				waitingLongDesc = &mods[mod_name].TODO;
			}
			else if ((p=lowerCase(s).find("@moos_changelog"))!=string::npos)
			{
				anyCommand=true;
				string changes = trim(s.substr(p+strlen("@moos_changelog")));
				//mods[mod_name].changeLog = changes;
				waitingLongDesc = &mods[mod_name].changeLog;
			}
			else if ((p=lowerCase(s).find("@moos_subscribe"))!=string::npos)
			{
				anyCommand=true;

				vector<string> lstVars;
				string rest = s.substr(p+strlen("@moos_subscribe"));
				tokenize(rest,"\t ,;",lstVars);

				for (vector<string>::const_iterator v=lstVars.begin();v!=lstVars.end();++v)
				{
					string varNam = trim(*v);
					if (!varNam.empty())
					{
						vars[varNam]; // Already known vars?
						mods[mod_name].subscribes.insert(vars.getStored(varNam));	// Add dependencies:
					}
				}
				waitingLongDesc = NULL;
			}
			else if ((p=lowerCase(s).find("@moos_var"))!=string::npos)
			{
				anyCommand=true;

				string rest = trim(s.substr(p+strlen("@moos_var")));
				size_t p=rest.find_first_of(" \t");
				string varNam;
				if (p==string::npos && p>0)
					 varNam = rest;
				else varNam = rest.substr(0,p);

				if (varNam.empty())
				{
					std::cerr << format("[%s] @moos_var: Variable name empty, in line:\n%s",fil.wholePath.c_str(),s.c_str()) << std::endl;
					continue;
				}


				vars[varNam]; // Add to list.

				if (p!=string::npos) // There is a short desc:
					vars[vars.getStored(varNam)].short_desc = trim( rest.substr(p) );
				// Long desc?
				waitingLongDesc = &vars[vars.getStored(varNam)].desc;
			}
			else if ((p=lowerCase(s).find("@moos_publish"))!=string::npos)
			{
				anyCommand=true;

				string rest = trim(s.substr(p+strlen("@moos_publish")));
				size_t p=rest.find_first_of(", \t");
				string varNam;
				if (p==string::npos && p>0)
					 varNam = rest;
				else varNam = rest.substr(0,p);

				if (varNam.empty())
				{
					std::cerr << format("[%s] @moos_publish: Variable name empty, in line:\n%s",fil.wholePath.c_str(),s.c_str()) << std::endl;
					continue;
				}

				vars[varNam]; // Add to list.
				mods[mod_name].publishes.insert(vars.getStored(varNam));	// Add publishes

				if (p!=string::npos) // There is a short desc:
					vars[vars.getStored(varNam)].short_desc = trim( rest.substr(p) );
				// Long desc?
				waitingLongDesc = &vars[vars.getStored(varNam)].desc;
			}
			else if ((p=lowerCase(s).find("@moos_cmd"))!=string::npos)
			{
				anyCommand=true;

				string rest = trim(s.substr(p+strlen("@moos_cmd")));
				size_t p=rest.find_first_of(" \t");
				string cmdNam;
				if (p==string::npos && p>0)
					 cmdNam = rest;
				else cmdNam = rest.substr(0,p);

				cmds[cmdNam]; // Add to list.
				cmds[cmdNam][mod_name];

				mods[mod_name].commands.insert(cmdNam);	// Add accepted commands

				if (p!=string::npos) // There is a short desc:
					cmds[cmdNam][mod_name].short_desc = trim( rest.substr(p) );
				// Long desc?
				waitingLongDesc = &cmds[cmdNam][mod_name].desc;
			}
			else if ((p=lowerCase(s).find("@moos_param"))!=string::npos)
			{
				anyCommand=true;

				string rest = trim(s.substr(p+strlen("@moos_param")));
				size_t p=rest.find_first_of(" \t");
				string parNam;
				if (p==string::npos && p>0)
				{
					 parNam = rest;
					 rest.clear();
				}
				else
				{
					parNam = rest.substr(0,p);
					rest = trim(rest.substr(p));
				}

				mods[mod_name].params[parNam];  // Add accepted params

				mods[mod_name].params[parNam] = rest;
				// Long desc?
				waitingLongDesc = &mods[mod_name].params[parNam];
			}
			else if ((p=lowerCase(s).find("@moos"))==string::npos)
			{
				// This is a comment line WITHOUT a @moos tag.
				// If we are expecting a long description from a previous tag,
				//  go store it:
				if  (waitingLongDesc)
				{
					string lin = trim(s);
					if (lin.empty())
						lin = "\n";
					(*waitingLongDesc)+=lin;
				}
			}
		} // end for "l"
	} // end for "i"

	// autodetectedPublishVars:
	for (list<string>::const_iterator it=autodetectedPublishVars.begin();it!=autodetectedPublishVars.end();++it)
	{
		string varNam = trim(*it);
		if (!varNam.empty())
		{
			vars[varNam];// Add to list.
			mods[mod_name].publishes.insert(vars.getStored(varNam));	// Add publishes
		}
	}


	if (anyCommand)
		mods[mod_name].files.push_back(fil);
}

bool TApplication::generateOutputs()
{
	if ( CompareCI(opts.get("OUT_HTML"),"YES") )
	{
		if (!generateOutput_HTML())
		{
			cerr << "*ERROR* generating HTML output...\n";
			return false;
		}
	}
	return true;
}

bool TApplication::parseMissionFiles()
{
	for(TSourcesList::const_iterator i=lstMissionFiles.begin();i!=lstMissionFiles.end();++i)
        if (!parseOneMissionFile(*i))
            return false;

	return true;
}


bool TApplication::parseOneMissionFile( const TSourcesList::value_type fil )
{
	const string relPath = getMissionRelativePath( fil.wholePath ) ;
	cout << rightPad(string("Parsing ")+relPath,70);

	ifstream fi;
	fi.open(fil.wholePath.c_str());
	if (!fi.is_open())
	{
		cerr << "ERROR" << endl << "  Cannot open the file" << endl;
		return false;
	}

    TMissionFileInfo & mfi = missions[relPath];

	size_t  nLin=0,p;
	while (!fi.fail() && !fi.eof())
	{
		string lin;
		std::getline(fi,lin);
		nLin++;

		mfi.contents.push_back(lin);

		lin=trim(lin);

		// Ignore commented out parts:
        p=lin.find("//");
        if (p!=string::npos)
            lin = trim(lin.substr(0,p));
        if (lin.empty()) continue;

		// Look for Antler's "RUN" lines:
		// example:
		// 	Run = pGenericSensor       @	NewConsole=false ~ LASER_FRONT
        vector<string> toks;
        tokenize(lin,"\t =@",toks);
        if (toks.size()<2 || !CompareCI(toks[0],"Run"))
            continue;

        // This IS a Run line:
        // Get the entire right side:
        p=lin.find("=");
        if (p==string::npos) continue; // Shouldn't occur!
        string run_rhs = trim(lin.substr(p+1));
        if (run_rhs.empty()) continue; // Shouldn't

        // Now we have RHS like:
        // "pGenericSensor       @	NewConsole=false ~ LASER_FRONT"
        tokenize(run_rhs,"\t @",toks);
        if (toks.empty()) continue;

        std::string sModName = trim(toks[0]);
        // Naming conventions:
        // If the name starts with "p" or "i" + a capitalized letter,
        // remove that trailing letter:
        if (sModName.size()>=2)
        {
            if ((sModName[0]=='i' || sModName[0]=='p') &&
                (sModName[1]>='A' && sModName[1]<='Z') )
                sModName = sModName.substr(1);
        }

        mfi.modules.insert(sModName);

        if (toks.size()>1)
        {
            // Process "@" side:
        }
	}

	cout << "OK" << endl;
	return true;
}
