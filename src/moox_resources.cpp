/* +---------------------------------------------------------------------------+
   |                          The Mooxygen project                             |
   |                    http://code.google.com/p/mooxygen/                     |
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

#include "moox_utils.h"

using namespace std;
using namespace mooxygen;


void mooxygen::saveResourceToFile(const string &name, const string &trg_file)
{
	string data;

	if (name=="tabs.css")
	{
		data =
			"/* tabs styles, based on http://www.alistapart.com/articles/slidingdoors */\n"
			"DIV.tabs\n"
			"{\n"
   			"float            : left;\n"
			"   width            : 100%;\n"
			"   background       : url(\"tab_b.gif\") repeat-x bottom;\n"
			"   margin-bottom    : 4px;\n"
			"}\n"
			"DIV.tabs UL\n"
			"{\n"
			"   margin           : 0px;\n"
			"   padding-left     : 10px;\n"
			"   list-style       : none;\n"
			"}\n"
			"DIV.tabs LI, DIV.tabs FORM\n"
			"{\n"
			"   display          : inline;\n"
			"   margin           : 0px;\n"
			"   padding          : 0px;\n"
			"}\n"
			"DIV.tabs FORM\n"
			"{\n"
			"   float            : right;\n"
			"}\n"
			"DIV.tabs A\n"
			"{\n"
			"   float            : left;\n"
			"   background       : url(\"tab_r.gif\") no-repeat right top;\n"
			"   border-bottom    : 1px solid #84B0C7;\n"
			"   font-size        : x-small;\n"
			"   font-weight      : bold;\n"
			"   text-decoration  : none;\n"
			"}\n"
			"DIV.tabs A:hover\n"
			"{\n"
			"   background-position: 100% -150px;\n"
			"}\n"
			"\n"
			"DIV.tabs A:link, DIV.tabs A:visited,\n"
			"DIV.tabs A:active, DIV.tabs A:hover\n"
			"{\n"
			"       color: #1A419D;\n"
			"}\n"
			"DIV.tabs SPAN\n"
			"{\n"
			"   float            : left;\n"
			"   display          : block;\n"
			"   background       : url(\"tab_l.gif\") no-repeat left top;\n"
			"   padding          : 5px 9px;\n"
			"   white-space      : nowrap;\n"
			"}\n"
			"DIV.tabs INPUT\n"
			"{\n"
			"   float            : right;\n"
			"   display          : inline;\n"
			"   font-size        : 1em;\n"
			"}\n"
			"DIV.tabs TD\n"
			"{\n"
			"   font-size        : x-small;\n"
			"   font-weight      : bold;\n"
			"   text-decoration  : none;\n"
			"}\n"
			"/* Commented Backslash Hack hides rule from IE5-Mac \\*/\n"
			"DIV.tabs SPAN {float : none;}\n"
			"/* End IE5-Mac hack */\n"
			"DIV.tabs A:hover SPAN\n"
			"{\n"
			"   background-position: 0% -150px;\n"
			"}\n"
			"DIV.tabs LI.current A\n"
			"{\n"
			"   background-position: 100% -150px;\n"
			"   border-width     : 0px;\n"
			"}\n"
			"DIV.tabs LI.current SPAN\n"
			"{\n"
			"   background-position: 0% -150px;\n"
			"   padding-bottom   : 6px;\n"
			"}\n"
			"DIV.navpath\n"
			"{\n"
			"   background       : none;\n"
			"   border           : none;\n"
			"   border-bottom    : 1px solid #84B0C7;\n"
			"}\n"
			"table.mooxygen {\n"
			"	border-width: 1px 1px 1px 1px;\n"
			"	border-spacing: 2px;\n"
			"	border-style: solid solid solid solid;\n"
			"	border-color: black black black black ;\n"
			"	border-collapse: collapse;\n"
			"	background-color: white;\n"
			"}\n"
			"table.mooxygen th {\n"
			"	border-width: 1px 1px 1px 1px;\n"
			"	padding: 1px 1px 1px 1px;\n"
			"	border-style: solid solid solid solid;\n"
			"	border-color: black black black black ;\n"
			"	background-color: white;\n"
			"	-moz-border-radius: 0px 0px 0px 0px;\n"
			"}\n"
			"table.mooxygen td {\n"
			"	border-width: 1px 1px 1px 1px;\n"
			"	padding: 1px 1px 1px 1px;\n"
			"	border-style: solid solid solid solid;\n"
			"	border-color: black black black black ;\n"
			//"	background-color: white;\n"
			"	-moz-border-radius: 0px 0px 0px 0px;\n"
			"}\n";
	}
	else if(name=="tab_b.gif")
	{
static const unsigned char tab_b[] = {
0x47,0x49,0x46,0x38,0x39,0x61,0x01,0x00,0x01,0x00,0x80,0x00,0x00,0x84,0xB0,0xC7,
0x00,0x00,0x00,0x2C,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x02,0x02,0x44,
0x01,0x00,0x3B,};
		data.resize(sizeof(tab_b));
		memcpy(&data[0],tab_b,sizeof(tab_b));
	}
	else if(name=="tab_r.gif")
	{
static const unsigned char tab_r[] = {
0x47,0x49,0x46,0x38,0x39,0x61,0x90,0x01,0x2C,0x01,0xD5,0x00,0x00,0xF6,0xF7,0xF9,
0xF1,0xF4,0xF7,0xF6,0xF8,0xFA,0xFC,0xFD,0xFE,0xFA,0xFB,0xFC,0xF9,0xFA,0xFB,0xF8,
0xF9,0xFA,0xEA,0xEF,0xF3,0xEF,0xF3,0xF6,0xC6,0xD5,0xDF,0xD2,0xDE,0xE6,0xD8,0xE2,
0xE9,0xDE,0xE7,0xED,0xDD,0xE6,0xEC,0xE5,0xEC,0xF1,0xE8,0xEE,0xF2,0xF4,0xF7,0xF9,
0xF3,0xF6,0xF8,0xB3,0xC8,0xD5,0xC1,0xD2,0xDD,0xCB,0xD9,0xE2,0xCF,0xDC,0xE4,0xD6,
0xE1,0xE8,0x96,0xB4,0xC5,0x9D,0xB9,0xC9,0xAF,0xC2,0xCD,0xBB,0xCE,0xD9,0xC3,0xD4,
0xDE,0xC2,0xD3,0xDD,0xC8,0xD7,0xE0,0xCC,0xDA,0xE2,0xD5,0xE1,0xE8,0xD9,0xE4,0xEA,
0xD7,0xE2,0xE8,0xE5,0xEC,0xF0,0xEB,0xF0,0xF3,0x84,0xB0,0xC7,0xD1,0xDE,0xE5,0xDC,
0xE6,0xEB,0xE3,0xEB,0xEF,0xEB,0xF1,0xF4,0xEE,0xF3,0xF5,0xF7,0xFA,0xFB,0xFB,0xFC,
0xFC,0xFF,0xFF,0xFF,0xFE,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2C,0x00,0x00,
0x00,0x00,0x90,0x01,0x2C,0x01,0x00,0x06,0xFF,0x40,0x92,0x70,0x48,0x2C,0x1A,0x8F,
0xC8,0xA4,0x72,0xC9,0x6C,0x3A,0x9F,0xD0,0xA8,0x74,0x4A,0xAD,0x5A,0xAF,0xD8,0xAC,
0x76,0x0B,0x95,0x68,0x3C,0xAC,0x70,0x6B,0x4C,0x2E,0x9B,0xCF,0xE8,0xB4,0x7A,0xCD,
0x6E,0xBB,0xDF,0xF0,0xB8,0x7C,0x4E,0xAF,0xDB,0xEF,0xF8,0xBC,0x7E,0xCF,0x77,0x0F,
0x56,0x10,0x16,0x1A,0x17,0x1C,0x61,0x2B,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,
0x8F,0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,
0x9F,0xA0,0x93,0x2A,0x10,0x01,0x29,0x15,0x5E,0x2C,0x2A,0xAA,0xAB,0xAC,0xAD,0xAE,
0xAF,0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,
0xBF,0xC0,0xC1,0xC2,0xC3,0xB6,0x10,0x10,0x29,0x0F,0x27,0x1D,0x17,0x15,0xC6,0xCE,
0xCF,0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,
0xDF,0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xDA,0xA5,0x28,0x22,0x0C,0x0C,0x12,0x12,
0x01,0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,
0xFF,0x00,0x03,0x0A,0x1C,0x48,0xB0,0xA0,0xC1,0x83,0x08,0x13,0xF2,0x4B,0x81,0x22,
0x19,0x03,0x13,0x83,0x52,0x48,0x9C,0x48,0xB1,0xA2,0xC5,0x8B,0x18,0x33,0x6A,0xDC,
0xC8,0xB1,0xA3,0xC7,0x8F,0x20,0x43,0x8A,0x1C,0x49,0xB2,0xA4,0xC9,0x93,0x28,0x53,
0xAA,0x5C,0xE9,0x11,0xC5,0x81,0x75,0x26,0x40,0x80,0x20,0xC1,0xB2,0xA6,0xCD,0x9B,
0x38,0x73,0xEA,0xDC,0xC9,0xB3,0xA7,0x4F,0xFF,0x96,0x28,0x1A,0xC2,0x04,0xB1,0x80,
0x44,0xD0,0xA3,0x48,0x93,0x2A,0x5D,0xCA,0xB4,0xA9,0xD3,0xA7,0x50,0xA3,0x4A,0x9D,
0x4A,0xB5,0xAA,0xD5,0xAB,0x58,0xB3,0x6A,0xDD,0xCA,0xB5,0xAB,0xD7,0xAF,0x53,0x0F,
0x38,0x34,0xB1,0x20,0x04,0x89,0x03,0x68,0xD3,0xAA,0x5D,0xCB,0xB6,0xAD,0xDB,0xB7,
0x70,0xE3,0xCA,0x9D,0x4B,0xB7,0xAE,0xDD,0xBB,0x78,0xF3,0xEA,0xDD,0xCB,0xB7,0xAF,
0xDF,0xBF,0x80,0x03,0xD3,0x7D,0x20,0xE2,0x44,0xCC,0x10,0x66,0x1F,0x28,0x5E,0xCC,
0xB8,0xB1,0xE3,0xC7,0x90,0x23,0x4B,0x9E,0x4C,0xB9,0xB2,0xE5,0xCB,0x98,0x33,0x6B,
0xDE,0xCC,0xB9,0xB3,0xE7,0xCF,0xA0,0x43,0x8B,0x1E,0x6D,0xB9,0xF0,0x43,0xC4,0x1F,
0x48,0x9C,0x58,0xCD,0xBA,0xB5,0xEB,0xD7,0xB0,0x63,0xCB,0x9E,0x4D,0xBB,0xB6,0xED,
0xDB,0xB8,0x73,0xEB,0xDE,0xCD,0xBB,0xB7,0xEF,0xDF,0xC0,0x83,0x0B,0x1F,0x4E,0x1C,
0xF7,0xC3,0x05,0x1F,0x4A,0x94,0x20,0xC1,0xAE,0xB9,0xF3,0xE7,0xD0,0xA3,0x4B,0x9F,
0x4E,0xBD,0xBA,0xF5,0xEB,0xD8,0xB3,0x6B,0xDF,0xCE,0xBD,0xBB,0xF7,0xEF,0xE0,0xC3,
0x8B,0x1F,0x4F,0xBE,0x3C,0x76,0x13,0x31,0x91,0x2B,0x5F,0x2E,0xB3,0xBD,0xFB,0xF7,
0xF0,0xE3,0xCB,0x9F,0x4F,0xBF,0xBE,0xFD,0xFB,0xF8,0xF3,0xEB,0xDF,0xCF,0xBF,0xBF,
0xFF,0xFF,0x00,0x06,0x28,0xE0,0x80,0x04,0x16,0x98,0x5F,0x59,0xC9,0x95,0x40,0xC1,
0x72,0x88,0x35,0xE8,0xE0,0x83,0x10,0x46,0x28,0xE1,0x84,0x14,0x56,0x68,0xE1,0x85,
0x18,0x66,0xA8,0xE1,0x86,0x1C,0x76,0xE8,0xFF,0xE1,0x87,0x20,0x86,0x28,0xE2,0x88,
0x24,0x96,0xA8,0x61,0x82,0x14,0xA4,0x48,0x82,0x89,0x2C,0xB6,0xE8,0xE2,0x8B,0x30,
0xC6,0x28,0xE3,0x8C,0x34,0xD6,0x68,0xE2,0x07,0x09,0x2A,0xA8,0x22,0x8E,0x3C,0xF6,
0xE8,0xE3,0x8F,0x40,0x06,0x29,0xE4,0x90,0x44,0x16,0x69,0xE4,0x91,0x48,0x26,0xA9,
0xE4,0x92,0x4C,0x36,0xE9,0xE4,0x93,0x50,0x46,0x29,0xE5,0x94,0x54,0x26,0xA9,0x5C,
0x8A,0x3B,0x56,0xA9,0xE5,0x96,0x5C,0x76,0xE9,0xE5,0x97,0x60,0x86,0x29,0xE6,0x98,
0x5A,0x5E,0x89,0x25,0x09,0x64,0xA6,0xA9,0xE6,0x9A,0x6C,0xB6,0xE9,0xE6,0x9B,0x70,
0xFE,0x68,0x66,0x96,0x71,0xD6,0x69,0xE7,0x9D,0x78,0xE6,0xA9,0xE7,0x97,0x73,0x52,
0x80,0xE6,0x9E,0x80,0x06,0x2A,0xE8,0xA0,0x84,0xC2,0xD9,0xE7,0x9F,0x85,0x26,0xAA,
0xE8,0xA2,0x8C,0x36,0x3A,0xE4,0xA1,0x8E,0x46,0x2A,0xE9,0xA4,0x94,0xC6,0x09,0x69,
0xA5,0x98,0x66,0xAA,0xE9,0xA6,0x4F,0x5E,0xCA,0xE9,0xA7,0xA0,0x86,0xCA,0xA9,0xA7,
0xA2,0x96,0x6A,0xEA,0xA9,0x84,0x92,0x8A,0xEA,0xAA,0xAC,0xB6,0xCA,0xA6,0xAA,0xAE,
0xC6,0x2A,0xEB,0xAC,0x53,0xC2,0x4A,0xEB,0xAD,0xB8,0xE6,0x2A,0xA4,0xAD,0xBA,0xF6,
0xEA,0xEB,0xAC,0xBC,0xFE,0x2A,0xEC,0xB0,0xA5,0x06,0x4B,0xEC,0xB1,0xC8,0x56,0x6A,
0x6C,0xB2,0xCC,0x36,0x9B,0xE8,0xB2,0xCE,0x46,0x2B,0x2D,0x9E,0xD0,0x4E,0x6B,0xED,
0xB5,0x6B,0x56,0x8B,0xED,0xB6,0xDC,0x76,0xA9,0x6D,0xB7,0xE0,0x86,0xDB,0xA9,0x8E,
0x74,0x8A,0x6B,0xEE,0xB9,0x51,0x7E,0x8B,0xFF,0xEE,0xBA,0xEC,0xF2,0xA8,0x6E,0xBB,
0xF0,0x9A,0xFB,0x6E,0xBC,0xF4,0x72,0x3B,0x6F,0xBD,0xF8,0x4E,0x7B,0x6F,0xBE,0xFC,
0x32,0xBB,0x6F,0xBF,0x00,0x0F,0xFB,0x6F,0xC0,0x04,0xEB,0x3A,0x70,0xC1,0x08,0x03,
0x4B,0xAE,0x9F,0x09,0x37,0x1C,0xED,0xC1,0x0E,0x47,0x6C,0x2A,0xC4,0x12,0x57,0xFC,
0x29,0xC5,0x16,0x67,0x8C,0x29,0xC6,0x1A,0x77,0x1C,0x29,0xC7,0x1E,0x87,0xAC,0x28,
0xC8,0x22,0x97,0x2C,0x28,0xC9,0x26,0xA7,0x9C,0x27,0xCA,0x2A,0xB7,0x6C,0xE9,0xC2,
0x88,0xBA,0x2C,0x33,0xA5,0x2C,0xCF,0x6C,0x33,0x99,0x35,0xDF,0xAC,0x33,0x9F,0x30,
0xEF,0xEC,0xF3,0xB3,0x3D,0xFF,0x2C,0x74,0xA0,0x39,0x0F,0x6D,0xB4,0x93,0x45,0x1F,
0xAD,0xB4,0x95,0x41,0x2F,0xED,0x74,0x9B,0x49,0x3F,0x2D,0x35,0x90,0x51,0x4F,0x6D,
0x35,0x8E,0x55,0x5F,0x3D,0x75,0xD6,0x5A,0x3F,0xCD,0x75,0xD7,0x4B,0x7F,0x0D,0xF6,
0xD1,0x62,0x8F,0x3D,0x74,0xD9,0x66,0xFF,0x8C,0x76,0xDA,0x3B,0xAF,0xCD,0xF6,0xCD,
0x6E,0xBF,0x3D,0x73,0xDC,0x72,0xBB,0x4C,0x77,0xDD,0x2A,0xDF,0x8D,0xB7,0xC9,0x7A,
0xEF,0x2D,0x72,0xDF,0x7E,0x7B,0x0C,0x78,0xE0,0x1A,0x0F,0x4E,0xB8,0xC5,0x86,0x1F,
0x2E,0x71,0xE2,0x8A,0x3B,0xCC,0x78,0xE3,0x09,0x3F,0x0E,0x79,0xC1,0x92,0x4F,0x1E,
0x70,0xE5,0x96,0xF7,0x8B,0x79,0xE6,0xF9,0x6E,0xCE,0x79,0xBD,0x9E,0x7F,0x1E,0x6F,
0xE8,0xA2,0xB7,0x4B,0x7A,0xE9,0xEB,0x9E,0x8E,0xFA,0xB9,0xAA,0xAF,0x2E,0x6E,0xEB,
0xAE,0x83,0x0B,0x7B,0xEC,0xF6,0x36,0x4D,0xFF,0xBB,0xD6,0xB3,0xDF,0x7E,0x6D,0xEE,
0xBA,0xEB,0x6B,0x7B,0xEF,0x52,0xF3,0x0E,0xBC,0xB3,0xC2,0x0F,0xEF,0xEF,0xEF,0xC6,
0x2B,0x5D,0x7C,0xF2,0xC7,0x2E,0xCF,0xBC,0xC0,0xC8,0x3F,0x2F,0xB4,0xF3,0xD2,0xFB,
0x4A,0x7D,0xF5,0x06,0x47,0x8F,0xBD,0xCE,0xD7,0x6F,0x7F,0x6B,0xF7,0xDE,0x2B,0x8C,
0x25,0xC3,0xE1,0xAB,0xAD,0x7D,0xF9,0x76,0x9F,0x8F,0x7E,0xDE,0xEA,0xAF,0xCF,0x77,
0xFB,0xEE,0xFF,0x0D,0x7F,0xFC,0x82,0xCF,0x4F,0x7F,0xE1,0xF6,0xDF,0x8F,0x78,0xFE,
0xFA,0x2F,0xCE,0x7F,0xFF,0x8E,0xFB,0x1F,0x00,0x23,0x27,0xC0,0x01,0x52,0xAE,0x80,
0x06,0xBC,0x1C,0x02,0x13,0xA8,0xB9,0x05,0x32,0xB0,0x73,0x0E,0x7C,0x20,0xE8,0x22,
0x28,0xC1,0xD1,0x51,0xB0,0x82,0xA6,0xBB,0x20,0x06,0x53,0xA7,0xC1,0x0D,0xB2,0xAE,
0x83,0x1E,0x7C,0x1D,0x08,0x43,0x28,0xBB,0x11,0x92,0xB0,0x76,0xE3,0x8B,0xD9,0x09,
0x09,0x98,0xC2,0x15,0x46,0x0C,0x7C,0x2E,0x64,0x14,0x0C,0x63,0x38,0x32,0x13,0xD2,
0x50,0x5A,0x33,0xBC,0x61,0xAA,0x6C,0xA8,0xC3,0x66,0xE5,0xB0,0x87,0x44,0xE3,0x21,
0x10,0x91,0xF5,0xC3,0x21,0xEA,0xA9,0x88,0x46,0xA4,0x96,0x10,0x93,0x28,0x2C,0x24,
0x32,0xB1,0x4E,0x4E,0x7C,0xA2,0xA1,0x96,0x28,0xC5,0xEC,0xB5,0xB0,0x8A,0x16,0x4C,
0x21,0x17,0xB6,0xC8,0xC5,0x2E,0x7A,0xF1,0x8B,0x60,0x0C,0xA3,0x18,0xC7,0x48,0xC6,
0x2E,0x7A,0x01,0x0C,0x61,0x48,0xA3,0x1A,0xD7,0xC8,0xC6,0x36,0xBA,0xF1,0x8D,0x70,
0x8C,0xA3,0x1C,0xE7,0x48,0xC7,0x3A,0xDA,0xFF,0xF1,0x8E,0x78,0xCC,0xA3,0x1E,0xF7,
0xC8,0xC7,0x3E,0xFA,0xF1,0x8F,0x80,0x0C,0x64,0x1D,0xC7,0x40,0x80,0x00,0x08,0x82,
0x10,0x82,0x4C,0xA4,0x22,0x17,0xC9,0xC8,0x46,0x3A,0xF2,0x91,0x90,0x8C,0xA4,0x24,
0x13,0x39,0x86,0x02,0x08,0x20,0x00,0x28,0x38,0x85,0x06,0x26,0xC9,0xC9,0x4E,0x7A,
0xF2,0x93,0xA0,0x0C,0xA5,0x28,0x47,0xA9,0x46,0x42,0x5E,0xB2,0x21,0xCB,0xA8,0x00,
0x29,0x57,0xC9,0xCA,0x56,0xBA,0xF2,0x95,0xB0,0x6C,0xA4,0x29,0x31,0x99,0x0C,0x77,
0xC4,0xF2,0x96,0xB8,0xCC,0xA5,0x2E,0x77,0x19,0xCA,0x59,0xBA,0xE4,0x01,0x83,0xE0,
0xA5,0x30,0x87,0x49,0xCC,0x62,0x1A,0xF3,0x8D,0xBE,0x7C,0xC9,0x03,0x48,0x70,0xCC,
0x66,0x3A,0xF3,0x99,0xD0,0xEC,0x65,0x0B,0x08,0x70,0x4A,0xB1,0x88,0x80,0x04,0x7D,
0xC8,0xA6,0x36,0xB7,0xC9,0xCD,0x6E,0x7A,0xF3,0x9B,0xE0,0x0C,0xA7,0x38,0xFB,0x30,
0x00,0x02,0x90,0xC2,0x25,0x22,0xB8,0xE6,0x38,0xD7,0xC9,0xCE,0x76,0xBA,0xF3,0x9D,
0xF0,0x8C,0xA7,0x3C,0xC9,0x50,0xCE,0x51,0x60,0xF2,0x25,0xD7,0x24,0x80,0x3E,0xF7,
0xC9,0xCF,0x7E,0xFA,0xF3,0x9F,0x00,0x0D,0xA8,0x40,0x07,0x4A,0xD0,0x82,0x1A,0xF4,
0xA0,0x08,0x4D,0xA8,0x42,0x17,0xCA,0xD0,0x86,0x3A,0xF4,0xA1,0x10,0x8D,0xA8,0x44,
0x27,0x5A,0x50,0x4B,0x46,0x20,0x05,0xD6,0xBC,0x26,0x31,0x36,0xCA,0xD1,0x8E,0x7A,
0xF4,0xA3,0x20,0x0D,0xA9,0x48,0x47,0x4A,0x52,0x62,0x08,0x20,0x02,0xF7,0x4C,0xE7,
0x35,0xCF,0xC1,0xD2,0x96,0xBA,0xF4,0xA5,0xFF,0x30,0x8D,0xA9,0x4C,0x67,0x4A,0xD3,
0x9A,0x9A,0x23,0x02,0x28,0x65,0x08,0x3E,0xAF,0x89,0xD3,0x9E,0xFA,0xF4,0xA7,0x40,
0x0D,0xAA,0x50,0x87,0x4A,0xD4,0xA2,0x1A,0xF5,0xA8,0x48,0x4D,0xAA,0x52,0x97,0xCA,
0xD4,0xA6,0x3A,0xF5,0xA9,0x50,0x8D,0xAA,0x54,0xA7,0x4A,0xD5,0xAA,0x26,0x35,0x1D,
0x3B,0x25,0x81,0x55,0xB7,0xCA,0xD5,0xAE,0x7A,0xF5,0xAB,0x60,0x0D,0xAB,0x58,0xC7,
0x4A,0x56,0xAB,0xC2,0x43,0xA7,0x8B,0xD1,0x6A,0x59,0xD7,0xCA,0xD6,0xB6,0xBA,0xF5,
0xAD,0x70,0x8D,0xAB,0x5C,0x7F,0x8A,0x55,0xB4,0x90,0xC0,0xA6,0x78,0xCD,0xAB,0x5E,
0xF7,0xCA,0xD7,0xBE,0xFA,0xF5,0xAF,0xD0,0xC0,0x69,0x29,0x24,0x82,0x02,0x12,0x94,
0xF4,0xB0,0x88,0x4D,0xAC,0x62,0x17,0xCB,0xD8,0xC6,0x3A,0x76,0x15,0x02,0x88,0x2C,
0x04,0x04,0x0B,0x0F,0x12,0x14,0xE0,0xB2,0x98,0xCD,0xAC,0x66,0x37,0xCB,0xD9,0xCE,
0x7A,0xF6,0xB3,0xA0,0x0D,0xAD,0x68,0x47,0x4B,0xDA,0xD2,0x9A,0xF6,0xB4,0xA8,0x4D,
0xAD,0x6A,0x57,0xCB,0xDA,0xD6,0xBA,0xF6,0xB5,0xB0,0x15,0xAD,0x2A,0x24,0xDB,0x53,
0x12,0x50,0xF4,0xB6,0xB8,0xCD,0xAD,0x6E,0x77,0xCB,0xDB,0xDE,0xFA,0xF6,0xB7,0xC0,
0xC5,0x6D,0x01,0x20,0x2B,0x00,0x12,0x84,0xE2,0xB8,0xC8,0x4D,0xAE,0x72,0x97,0xCB,
0xDC,0xE6,0x3A,0xF7,0xB9,0xD0,0x45,0xAE,0x3F,0xB1,0x39,0xCF,0xEA,0x5A,0xF7,0xBA,
0xD8,0xCD,0xAE,0x76,0xBF,0x39,0x80,0xEE,0x22,0x82,0xBA,0xDB,0x0D,0xAF,0x78,0xC7,
0x4B,0xDE,0xF2,0x62,0x97,0x99,0xD1,0x4C,0xFF,0xAF,0x7A,0xD7,0xCB,0x5E,0x41,0xA2,
0xB7,0xBD,0xF0,0x8D,0xAF,0x7C,0xE7,0x1B,0x86,0xF7,0xD2,0xF7,0xBE,0xF8,0xCD,0xAF,
0x30,0xED,0xAB,0xDF,0xFE,0xFA,0xF7,0xBF,0xA1,0xE4,0x2F,0x80,0x07,0x4C,0xE0,0x02,
0xBB,0xD7,0xC0,0x08,0x4E,0xB0,0x82,0xEF,0x28,0xE0,0x05,0x3B,0xF8,0xC1,0x09,0x6E,
0x30,0x84,0x27,0x4C,0x61,0xFD,0x4A,0xB8,0xC2,0x18,0xCE,0x30,0x7B,0x2F,0xAC,0xE1,
0x0E,0x7B,0xD8,0x98,0x1C,0xFE,0xB0,0x88,0x47,0x7C,0xCB,0x10,0x93,0xF8,0xC4,0x28,
0x16,0xA5,0x89,0x53,0xCC,0xE2,0x16,0x43,0x72,0xC5,0x2E,0x8E,0xB1,0x8C,0x01,0x09,
0xE3,0x19,0xDB,0xF8,0xC6,0x76,0xAC,0x31,0x8E,0x77,0xCC,0x63,0x36,0xEA,0xB8,0xC7,
0x40,0xDE,0xF1,0x8F,0x83,0x4C,0x64,0x19,0x0F,0xB9,0xC8,0x48,0x4E,0xF1,0x91,0x93,
0xCC,0x64,0x11,0x2F,0xB9,0xC9,0x50,0xCE,0xF0,0x93,0xA3,0x4C,0x65,0x08,0x4F,0xB9,
0xCA,0x58,0x8E,0x70,0x96,0xB7,0x7C,0xE2,0x2B,0x73,0xF9,0xCB,0xFD,0xF5,0x32,0x98,
0xC7,0x4C,0x5F,0x31,0x93,0xF9,0xCC,0xED,0x35,0x33,0x9A,0xD7,0x1C,0x4D,0x35,0xB3,
0xF9,0xCD,0xC7,0x74,0x33,0x9C,0xE7,0xBC,0x5F,0x3A,0xDB,0xD9,0xC2,0x77,0xCE,0x73,
0x99,0xF5,0xCC,0x67,0xF8,0xCA,0xB9,0xCF,0x80,0x0E,0x70,0xA0,0x07,0xFD,0xCC,0x3F,
0x13,0xFA,0xD0,0x2F,0x46,0xB4,0xA2,0xEB,0xBC,0xE8,0x46,0xE3,0xD2,0xD0,0x8E,0x8E,
0x74,0x1F,0x21,0x2D,0xE9,0x4A,0xE3,0x91,0xD2,0x96,0xCE,0xF4,0x1C,0x31,0xAD,0xE9,
0x4E,0xBB,0x91,0xD3,0x9E,0x0E,0x75,0x1A,0xFF,0x41,0x2D,0xEA,0x50,0x93,0xBA,0xD4,
0x9D,0x3E,0x35,0xAA,0x33,0xAD,0xEA,0x55,0x57,0xBA,0xD5,0xAE,0x8E,0x34,0xAC,0x63,
0xDD,0xE8,0x59,0xD3,0x5A,0xD1,0xB6,0xBE,0xF5,0xA1,0x73,0xAD,0xEB,0x41,0xF3,0xBA,
0xD7,0x80,0xFE,0x35,0xB0,0xF9,0x2C,0xEC,0x61,0xE7,0xB9,0xD8,0xC6,0xB6,0x33,0xB2,
0x93,0x3D,0xE7,0x65,0x33,0xFB,0xCD,0xCE,0x7E,0xF6,0x9A,0xA3,0x2D,0xED,0x33,0x53,
0xBB,0xDA,0x63,0xBE,0x36,0xB6,0xBF,0xAC,0xED,0x6D,0x6F,0xB9,0xDB,0xDE,0xC6,0x32,
0xB8,0xC3,0x4D,0xE5,0x71,0x93,0x1B,0xCA,0xE6,0x3E,0x37,0x93,0xD3,0xAD,0x6E,0x24,
0xB3,0xBB,0xDD,0x44,0x7E,0x37,0xBC,0x81,0x2C,0xEF,0x79,0xF3,0xB8,0xDE,0xF6,0xC6,
0x31,0xBE,0xF3,0x6D,0xE3,0x7D,0xF3,0xDB,0xC8,0xFF,0x76,0xB5,0xBF,0x03,0xDE,0xE2,
0x81,0x13,0x5C,0xC9,0x07,0x2F,0xB5,0xC1,0x13,0x4E,0xE2,0x85,0x33,0xDC,0xC9,0x0F,
0xF7,0xB4,0xC3,0x23,0xDE,0xE1,0x89,0x53,0x5C,0xCA,0x17,0x67,0x75,0xC6,0x2D,0x6D,
0xF1,0x8D,0x4F,0xB8,0xE3,0x1E,0x7F,0x30,0xC8,0x43,0xBE,0xE0,0x91,0x93,0x5C,0xCB,
0x27,0x5F,0xB4,0xC9,0x53,0x5E,0xE0,0x95,0xB3,0x7C,0xC0,0x2E,0x7F,0xF9,0x7F,0x63,
0x2E,0xF3,0x30,0xD7,0x9C,0xD0,0x34,0xBF,0x39,0x7E,0x73,0xAE,0xF3,0x3D,0xF7,0xBC,
0xCF,0x3C,0xFF,0x79,0x7C,0x83,0x2E,0xF4,0x34,0x17,0x5D,0xCF,0x44,0x3F,0xBA,0x7A,
0x93,0xAE,0xF4,0x36,0x37,0x5D,0xD9,0x4F,0xA7,0x33,0xD3,0xA3,0xDE,0xCC,0xA9,0x53,
0x1D,0xC4,0x57,0x87,0x76,0xD6,0xD9,0x6C,0x3E,0xF5,0xAD,0x33,0xDA,0xEB,0x64,0xEE,
0x3A,0xD8,0x75,0x29,0xF6,0xB1,0x3F,0xDA,0xEC,0xD9,0x46,0x3B,0x98,0xCB,0xAE,0xF6,
0x57,0xB2,0xBD,0xED,0xAD,0x7C,0x3B,0xDC,0x57,0x29,0xF7,0xB9,0x8F,0xB2,0xEE,0x76,
0x17,0x74,0xDE,0xCB,0xBD,0x77,0xBE,0xF7,0x1D,0xDD,0x7F,0x07,0x7C,0xE0,0xD7,0x3D,
0x78,0xC2,0x17,0xDE,0xDD,0x41,0x00,0x00,0x3B,};
		data.resize(sizeof(tab_r));
		memcpy(&data[0],tab_r,sizeof(tab_r));
	}
	else if(name=="tab_l.gif")
	{
static const unsigned char tab_l[] = {
0x47,0x49,0x46,0x38,0x39,0x61,0x09,0x00,0x2C,0x01,0xD5,0x00,0x00,0xF6,0xF7,0xF9,
0xF1,0xF4,0xF7,0xF6,0xF8,0xFA,0xFC,0xFD,0xFE,0xFA,0xFB,0xFC,0xF9,0xFA,0xFB,0xF8,
0xF9,0xFA,0xEA,0xEF,0xF3,0xEF,0xF3,0xF6,0xC6,0xD5,0xDF,0xD2,0xDE,0xE6,0xD8,0xE2,
0xE9,0xDE,0xE7,0xED,0xDD,0xE6,0xEC,0xE5,0xEC,0xF1,0xE8,0xEE,0xF2,0xF4,0xF7,0xF9,
0xF3,0xF6,0xF8,0xB3,0xC8,0xD5,0xC1,0xD2,0xDD,0xCB,0xD9,0xE2,0xCF,0xDC,0xE4,0xD6,
0xE1,0xE8,0x96,0xB4,0xC5,0x9D,0xB9,0xC9,0xAF,0xC2,0xCD,0xBB,0xCE,0xD9,0xC3,0xD4,
0xDE,0xC2,0xD3,0xDD,0xC8,0xD7,0xE0,0xCC,0xDA,0xE2,0xD5,0xE1,0xE8,0xD9,0xE4,0xEA,
0xD7,0xE2,0xE8,0xE5,0xEC,0xF0,0xEB,0xF0,0xF3,0x84,0xB0,0xC7,0xD1,0xDE,0xE5,0xDC,
0xE6,0xEB,0xE3,0xEB,0xEF,0xEB,0xF1,0xF4,0xEE,0xF3,0xF5,0xF7,0xFA,0xFB,0xFB,0xFC,
0xFC,0xFF,0xFF,0xFF,0xFE,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2C,0x00,0x00,
0x00,0x00,0x09,0x00,0x2C,0x01,0x00,0x06,0xFF,0x40,0x96,0x50,0xB1,0xC9,0x60,0x48,
0x24,0x21,0x25,0x43,0x71,0x00,0x56,0x03,0x16,0x65,0x32,0x1A,0x58,0xAD,0x8A,0xCC,
0x08,0x4A,0x28,0x08,0x04,0x93,0xC4,0xA0,0x2B,0x80,0x98,0x33,0x0D,0x32,0x24,0xC0,
0xC6,0x20,0xBC,0x6B,0x76,0x8A,0xE4,0x2D,0xCB,0xE7,0xF5,0x75,0x2A,0x85,0x22,0x7D,
0xE3,0x7C,0x7D,0x7F,0x01,0x7C,0x07,0x07,0x7E,0x71,0x28,0x0F,0x22,0x0C,0x24,0x66,
0x84,0x07,0x0C,0x0C,0x27,0x8E,0x6C,0x28,0x8C,0x26,0x26,0x24,0x72,0x91,0x99,0x0B,
0x9B,0x90,0x0C,0x26,0x0B,0x21,0xA0,0x29,0x0F,0xA2,0xA4,0x9B,0x7B,0xA8,0xA3,0xA5,
0x72,0xAD,0xAA,0xB0,0xA9,0xAF,0x84,0xB1,0xAF,0xAC,0xB4,0xA6,0xB7,0xBB,0xBA,0xB3,
0xAE,0xAB,0xA7,0xBE,0xB6,0xC3,0xC2,0xC0,0xBF,0xB2,0xB9,0xC7,0xC4,0xCB,0xC6,0xB2,
0xCC,0xC9,0xCE,0xB5,0xD2,0xBD,0xCD,0xBC,0x84,0xD4,0xC8,0xD3,0xD7,0xD0,0xB8,0xD9,
0xDD,0xD5,0xCF,0xD9,0xCA,0xE2,0xDC,0xDF,0xE3,0xE7,0xE6,0xEA,0xBE,0xE4,0xDB,0xC5,
0xEB,0xC7,0xED,0xE1,0xEE,0xD6,0xEC,0xE9,0xEF,0xF8,0xF1,0xF7,0xF5,0xFC,0xD1,0xF0,
0xE5,0xF9,0xFC,0x05,0xA4,0x07,0x50,0xDF,0x3F,0x82,0x08,0x83,0x1D,0x9C,0xC7,0x10,
0xDB,0x42,0x6D,0x0D,0xE5,0x41,0x9C,0x08,0xCE,0xE1,0xC0,0x86,0x15,0x25,0x56,0xDC,
0x88,0xEE,0x21,0xC7,0x6B,0x1A,0xF7,0x15,0x14,0xD8,0x2F,0xE1,0xC4,0x90,0x1E,0x3B,
0x5E,0xA4,0xA8,0xB2,0x24,0xC6,0x96,0x23,0x4D,0x66,0x14,0x29,0x13,0x66,0xCD,0x87,
0x28,0x57,0xCE,0x4C,0x89,0x93,0xE6,0x4B,0xE7,0x90,0xD2,0x84,0xB0,0x20,0x92,0x01,
0x49,0x12,0x29,0x4C,0x1C,0x18,0x10,0x3A,0x65,0x44,0x0B,0xA1,0x43,0xB5,0xB4,0x78,
0x2A,0x34,0x0C,0x55,0xA8,0x68,0xA0,0x0A,0x25,0x11,0x41,0xAB,0x90,0xA3,0x5E,0xC1,
0x4E,0x1D,0x4B,0x62,0xAC,0xD9,0x16,0x65,0xA7,0x0E,0x58,0xB1,0x82,0x00,0x81,0xB4,
0x6B,0xBB,0x78,0x21,0xC1,0xD6,0xED,0x97,0x32,0x74,0xDD,0xD6,0x09,0x00,0x21,0xAF,
0x9A,0x35,0x74,0xDB,0xE6,0xE9,0x1B,0x97,0xC0,0x5D,0x01,0x24,0xAC,0xB4,0x25,0x83,
0x58,0xED,0xE2,0x2E,0x69,0x5B,0xAC,0x5D,0x1C,0x59,0xAD,0x95,0xCA,0x66,0x8F,0x9E,
0x45,0xEB,0xF5,0x6B,0x67,0x16,0x60,0xB5,0x86,0x86,0x3A,0x7A,0xEB,0xE7,0xD2,0x9E,
0x3B,0xA3,0x06,0x7D,0xBA,0xB5,0x6A,0xD7,0x61,0x61,0x8B,0x96,0x4D,0x9A,0xB6,0xE9,
0xD7,0xB8,0x63,0xE7,0x9E,0xBD,0xBB,0x76,0xEF,0xDB,0xBA,0x83,0xF3,0x16,0xEE,0x9B,
0x38,0xF0,0xE1,0xC8,0x8B,0x27,0x3F,0xAE,0xBC,0x39,0xF3,0xE7,0xA9,0x8D,0x47,0x5F,
0x3E,0xDD,0x79,0x75,0xE8,0xAC,0x7F,0x5F,0xDF,0x9E,0x5D,0x7A,0x77,0xEA,0xDF,0xAD,
0x87,0xC7,0xBE,0xBA,0xBC,0x6D,0xEE,0xE6,0xB5,0x8F,0x47,0x7F,0x7E,0xBD,0xFB,0xF4,
0xDE,0xE1,0x83,0x97,0x2F,0x9E,0x3E,0xF9,0xF6,0xF6,0xD9,0xAB,0xCF,0xFF,0x1E,0xBF,
0xFF,0xFD,0xFF,0xC5,0x17,0xE0,0x7C,0x03,0xD6,0x57,0xE0,0x7D,0x00,0x76,0x16,0x04,
0x00,0x3B,};
		data.resize(sizeof(tab_l));
		memcpy(&data[0],tab_l,sizeof(tab_l));
	}
	else
		throw runtime_error(format("Unknown resource file: %s",name.c_str()));


	// Save to file:
	ofstream  f(trg_file.c_str());
	if (!f.is_open())
		throw runtime_error(format("Cannot write to file: %s",trg_file.c_str()));

	if (!data.empty())
		f.write(&data[0],data.size());
}
