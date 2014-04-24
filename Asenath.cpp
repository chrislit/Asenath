// Copyright 2001 by Christopher C. Little

// Asenath.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "httpext.h"

#include "corediatheke.h"

#include <string>
#include <strstream>

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

BOOL WINAPI GetExtensionVersion(HSE_VERSION_INFO *pVer)
{
	pVer->dwExtensionVersion = HSE_VERSION;
	strncpy(pVer->lpszExtensionDesc, "Asenath ISAPI Extension", HSE_MAX_EXT_DLL_NAME_LEN);
	return TRUE;
}

void WriteContext(EXTENSION_CONTROL_BLOCK *pECB, const char *pszFormat, ...)
{
	char szBuffer[1024];
	va_list arg_ptr;
	va_start(arg_ptr, pszFormat); 
	vsprintf(szBuffer, pszFormat, arg_ptr);
	va_end(arg_ptr);

	DWORD dwSize = strlen(szBuffer);
	pECB->WriteClient(pECB->ConnID, szBuffer, &dwSize, 0);
}

void StartContext(EXTENSION_CONTROL_BLOCK *pECB, bool palm)
{
	if (!palm) {
		WriteContext(pECB, "<html><head>");
		WriteContext(pECB, "<title>Diatheke Interlinear Bible</title>");
		WriteContext(pECB, "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">");
		WriteContext(pECB, "<meta name=\"palmcomputingplatform\" content=\"true\">");
		WriteContext(pECB, "<meta name=\"historylisttext\" content=\"Diatheke\">");
		WriteContext(pECB, "<style type=\"text/css\">");
		WriteContext(pECB, "#divBottom{position:absolute; visibility:hidden; font-family:arial,helvetica; height:30; width:100; font-size:10pt; font-weight:bold}");
		WriteContext(pECB, "A:link, A:visited, A:active{text-decoration: none}");
		WriteContext(pECB, "</style>");
		WriteContext(pECB, "<script type=\"text/javascript\" language=\"JavaScript\">");
		WriteContext(pECB, "/********************************************************************************");
		WriteContext(pECB, "Copyright (C) 1999 Thomas Brattli");
		WriteContext(pECB, "This script is made by and copyrighted to Thomas Brattli at www.bratta.com");
		WriteContext(pECB, "Visit for more great scripts. This may be used freely as long as this msg is intact!");
		WriteContext(pECB, "I will also appriciate any links you could give me.");
		WriteContext(pECB, "********************************************************************************/");
		WriteContext(pECB, "//Default browsercheck, added to all scripts!");
		WriteContext(pECB, "function checkBrowser(){");
		WriteContext(pECB, "this.ver=navigator.appVersion;");
		WriteContext(pECB, "this.dom=document.getElementById?1:0;");
		WriteContext(pECB, "this.ie5=( (this.ver.indexOf(\"MSIE 6\")>-1 || this.ver.indexOf(\"MSIE 5\")>-1) && this.dom)?1:0;");
		WriteContext(pECB, "this.ie4=(document.all && !this.dom)?1:0;");
		WriteContext(pECB, "this.ns5=(this.dom && parseInt(this.ver) >= 5) ?1:0;");
		WriteContext(pECB, "this.ns4=(document.layers && !this.dom)?1:0;");
		WriteContext(pECB, "this.bw=(this.ie5 || this.ie4 || this.ns4 || this.ns5);");
		WriteContext(pECB, "return this;");
		WriteContext(pECB, "}");
		WriteContext(pECB, "bw=new checkBrowser()");
		WriteContext(pECB, "/********************************************************************************");
		WriteContext(pECB, "Remeber to set the look of the divBottom layer in the stylesheet (if you wan't");
		WriteContext(pECB, "another font or something)");
		WriteContext(pECB, "********************************************************************************/");
		WriteContext(pECB, "/*Set these values, gright for how much from the right you wan't the layer to go");
		WriteContext(pECB, "and gbottom for how much from the bottom you want it*/");
		WriteContext(pECB, "var gright=160");
		WriteContext(pECB, "var gbottom=80");
		WriteContext(pECB, "/********************************************************************************");
		WriteContext(pECB, "Constructing the ChangeText object");
		WriteContext(pECB, "********************************************************************************/");
		WriteContext(pECB, "function makeObj(obj,nest){");
		WriteContext(pECB, "nest=(!nest) ? '':'document.'+nest+'.';");
		WriteContext(pECB, "this.css=bw.dom? document.getElementById(obj).style:bw.ie4?document.all[obj].style:bw.ns4?eval(nest+\"document.layers.\" +obj):0;");
		WriteContext(pECB, "this.moveIt=b_moveIt;");
		WriteContext(pECB, "}");
		WriteContext(pECB, "function b_moveIt(x,y){this.x=x; this.y=y; this.css.left=this.x; this.css.top=this.y}");
		WriteContext(pECB, "/********************************************************************************");
		WriteContext(pECB, "Initilizing the page, getting height and width to moveto and calls the ");
		WriteContext(pECB, "object constructor");
		WriteContext(pECB, "********************************************************************************/");
		WriteContext(pECB, "function geoInit(){");
		WriteContext(pECB, "oGeo=new makeObj('divBottom');");
		WriteContext(pECB, "pageWidth=(bw.ie4 || bw.ie5)?document.body.offsetWidth-4:innerWidth;");
		WriteContext(pECB, "pageHeight=(bw.ie4 || bw.ie5)?document.body.offsetHeight-2:innerHeight;");
		WriteContext(pECB, "checkIt();");
		WriteContext(pECB, "// sets the resize handler.");
		WriteContext(pECB, "onresize=resized;");
		WriteContext(pECB, "if(bw.ie4 || bw.ie5) window.onscroll=checkIt;");
		WriteContext(pECB, "// shows the div");
		WriteContext(pECB, "oGeo.css.visibility='visible';");
		WriteContext(pECB, "}");
		WriteContext(pECB, "/********************************************************************************");
		WriteContext(pECB, "This function executes onscroll in ie and every 30 millisecond in ns");
		WriteContext(pECB, "and checks if the user have scrolled, and if it has it moves the layer.");
		WriteContext(pECB, "********************************************************************************/");
		WriteContext(pECB, "function checkIt(){");
		WriteContext(pECB, "if(bw.ie4 || bw.ie5) oGeo.moveIt(document.body.scrollLeft +pageWidth-gright,document.body.scrollTop+pageHeight-gbottom);");
		WriteContext(pECB, "else if(bw.ns4){");
		WriteContext(pECB, "oGeo.moveIt(window.pageXOffset+pageWidth-gright, window.pageYOffset+pageHeight-gbottom);");
		WriteContext(pECB, "setTimeout('checkIt()',30);");
		WriteContext(pECB, "}");
		WriteContext(pECB, "}");
		WriteContext(pECB, "//Adds a onresize event handler to handle the resizing of the window.");
		WriteContext(pECB, "function resized(){");
		WriteContext(pECB, "pageWidth=(bw.ie4 || bw.ie5)?document.body.offsetWidth-4:innerWidth;");
		WriteContext(pECB, "pageHeight=(bw.ie4 || bw.ie5)?document.body.offsetHeight-2:innerHeight;");
		WriteContext(pECB, "if(bw.ie4 || bw.ie5) checkIt()");
		WriteContext(pECB, "}");
		WriteContext(pECB, "//Calls the geoInit onload");
		WriteContext(pECB, "if(bw.bw && !bw.ns5) onload=geoInit;");
		WriteContext(pECB, "//Here we will write the div out so that lower browser won't see it.'");
		WriteContext(pECB, "if(bw.bw && !bw.ns5) document.write('<div id=\"divBottom\"><table><tr><td align=\"center\">Powered by<br /><img src=\"http://www.crosswire.org/sword/pbsword.gif\"><br /><a href=\"http://www.crosswire.org/\">www.crosswire.org</td></tr></table></div>')");
		WriteContext(pECB, "</script>");
		WriteContext(pECB, "</head>");
		WriteContext(pECB, "<body>");
	}
	else {
		WriteContext(pECB, "<html><head>");
		WriteContext(pECB, "<title>HANDiatheke</title>");
		WriteContext(pECB, "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">");
		WriteContext(pECB, "<meta name=\"palmcomputingplatform\" content=\"true\">");
		WriteContext(pECB, "<meta name=\"historylisttext\" content=\"HANDiatheke\">");
		WriteContext(pECB, "</head>");
		WriteContext(pECB, "<body>");
	}
}

void EndContext(EXTENSION_CONTROL_BLOCK *pECB, bool palm)
{
	if (palm) {
		WriteContext(pECB, "<hr>Powered by Diatheke (http://www.crosswire.org/sword/diatheke) and the SWORD Project (http://www.crosswire.org/sword).");
	}

	WriteContext(pECB, "<br /><br /><br /><br /></body></html>");
}

DWORD WINAPI HttpExtensionProc(EXTENSION_CONTROL_BLOCK *pECB)
{
	int maxverses = -1;
	unsigned char outputformat = FMT_CGI, searchtype = ST_NONE, outputencoding = ENC_UTF8;
	unsigned long optionfilters = OP_NONE;
	std::string locale, ref, script, range, defversion;
	signed short variants = 0;
	bool debugmode = false, palm = false;

	std::string qstring;
	std::string savestring = "Asenath.dll?";
	std::string val, key;

	std::list<std::string> versionlist;

	string::size_type pos;

	qstring = pECB->lpszQueryString;
	unsigned char c;
	for (int i = 0; i < qstring.length(); i++) {
		if (qstring[i] == '+') {
			qstring[i] = ' ';
		}
		else if (qstring[i] == '%') {
			if (qstring[i+1] > 57) {
				c = 16 * (10 + toupper(qstring[i+1]) - 'A');
			}
			else {
				c = 16 * (qstring[i+1] - '0');
			}

			if (qstring[i+2] > 57) {
				c += 10 + toupper(qstring[i+2]) - 'A';
			}
			else {
				c += qstring[i+2] - '0';
			}

			qstring[i] = c;
			qstring.erase(i+1, 2);
		}
	}

	while (qstring.length()) {
		pos = qstring.find("&");
		if (pos != string::npos) {
			key = qstring.substr(0, pos);
			qstring.erase(0, pos+1);
		}
		else {
			key = qstring;
			qstring = "";
		}

		pos = key.find("=");
		if (pos != string::npos) {
			val = key.substr(pos+1, key.length()-(pos+1));
			key.erase(pos, key.length()-pos);
		}
		else {
			val = "";
		}

		if (!stricmp (key.c_str(), "verse")) {
			ref = val;
		}
		else if (!stricmp (key.c_str(), "search")) {
			if (!stricmp (val.c_str(), "phrase")) {
				searchtype = ST_PHRASE;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (val.c_str(), "regex")) {
				searchtype = ST_REGEX;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (val.c_str(), "multiword")) {
				searchtype = ST_MULTIWORD;
				savestring += key + "=" + val + "&";
			}
		}
		else if (!stricmp (key.c_str(), "range")) {
			range = val;
			savestring += key + "=" + val + "&";
		}
		else if (!stricmp (key.c_str(), "maxverses")) {
			maxverses = atoi(val.c_str());
			savestring += key + "=" + val + "&";
		}
		else if (!stricmp (key.c_str(), "variants")) {
			variants = atoi(val.c_str());
			savestring += key + "=" + val + "&";
		}
		else if (!stricmp (key.c_str(), "locale")) {
			locale = val;
			savestring += key + "=" + val + "&";
		}
		else if (!stricmp (key.c_str(), "debug")) {
			debugmode = true;
			savestring += key + "=" + val + "&";
		}
		else if (!stricmp (key.c_str(), "palm")) {
			palm = true;
			savestring += key + "=" + val + "&";
		}
		else if (!stricmp (key.c_str(), "defversion")) {
			defversion = val;
			savestring += key + "=" + val + "&";
		}
		else if (stricmp (val.c_str(), "off")) {
			if (!stricmp (key.c_str(), "strongs")) {
				optionfilters |= OP_STRONGS;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "footnotes")) {
				optionfilters |= OP_FOOTNOTES;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "headings")) {
				optionfilters |= OP_HEADINGS;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "morph")) {
				optionfilters |= OP_MORPH;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "hebcant")) {
				optionfilters |= OP_CANTILLATION;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "hebvowels")) {
				optionfilters |= OP_HEBREWPOINTS;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "grkacc")) {
				optionfilters |= OP_GREEKACCENTS;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "lemmas")) {
				optionfilters |= OP_LEMMAS;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "scriprefs")) {
				optionfilters |= OP_SCRIPREF;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "arshape")) {
				optionfilters |= OP_ARSHAPE;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "bidi")) {
				optionfilters |= OP_BIDI;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "redletters")) {
				optionfilters |= OP_RED;
				savestring += key + "=" + val + "&";
			}
			else if (!stricmp (key.c_str(), "latinxlit")) {
				script = "Latin";
				savestring += key + "=" + val + "&";
			}
			else
				versionlist.push_back(string(key));
		}
	}	

	if (!locale.length()) {
		unsigned long dsize = 2083;
		char * data = new char[2083];
		pECB->GetServerVariable(pECB->ConnID, "ACCEPT_LANGUAGE", data, &dsize);
		if (dsize) {
			locale = data;
			pos = locale.find("_");
			if (pos != string::npos)
				locale = locale.substr(0,pos);
		}
		else {
			locale = "abbr";
		}
	}

	StartContext(pECB, palm);

	if (versionlist.size() == 0)
		if (defversion.length())
			versionlist.push_back(defversion);
		else 
			versionlist.push_back("KJV");
	
	while (versionlist.size() > 0)
	{	
		ostrstream * output = new ostrstream();
		doquery(maxverses, outputformat, outputencoding, optionfilters, searchtype, range.c_str(), versionlist.front().c_str(), locale.c_str(), ref.c_str(), output, script.c_str(), variants);
		*output << ends;
		qstring = output->str();
		delete output;
		while ((pos = qstring.find("!DIATHEKE_URL!")) && pos != string::npos) {
			qstring.replace(pos, 14, savestring.c_str());
		}
		DWORD dwSize = qstring.length();
		pECB->WriteClient(pECB->ConnID, (void*)qstring.c_str(), &dwSize, 0);
		WriteContext(pECB, "<br /><br />");
		versionlist.pop_front();
	}	

	EndContext(pECB, palm);

	return HSE_STATUS_SUCCESS;
}
