# Microsoft Developer Studio Project File - Name="Asenath" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Asenath - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Asenath.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Asenath.mak" CFG="Asenath - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Asenath - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Asenath - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Asenath - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ASENATH_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /w /W0 /GX /O2 /I "../../sword/include" /I "../../sword/src/utilfuns/win32" /I "../../icu-sword/include" /I "../../sword/apps/console/diatheke" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ASENATH_EXPORTS" /D "_ICU_" /D "_ICUSWORD_" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib libsword.lib icuin.lib icuuc.lib /nologo /dll /machine:I386 /libpath:"../../sword/lib/vcppmake/vc6/libsword___Win32_Release_with_ICU" /libpath:"../../icu-sword/lib"

!ELSEIF  "$(CFG)" == "Asenath - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ASENATH_EXPORTS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /w /W0 /Gm /GX /ZI /Od /I "../../sword/include" /I "../../sword/src/utilfuns/win32" /I "../../icu-sword/include" /I "../../sword/apps/console/diatheke" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ASENATH_EXPORTS" /D "_ICU_" /D "_ICUSWORD_" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib libsword.lib icuin.lib icuuc.lib /nologo /dll /debug /machine:I386 /pdbtype:sept /libpath:"../../sword/lib/vcppmake/vc6/libsword___Win32_Debug_with_ICU" /libpath:"../../icu-sword/lib"

!ENDIF 

# Begin Target

# Name "Asenath - Win32 Release"
# Name "Asenath - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Diatheke Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\corediatheke.cpp
# End Source File
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\diafiltmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\diatheke.cpp
# End Source File
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\diathekemgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\gbfcgi.cpp
# End Source File
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\thmlcgi.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\Asenath.cpp
# End Source File
# Begin Source File

SOURCE=.\Asenath.def
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Diatheke Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\corediatheke.h
# End Source File
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\diafiltmgr.h
# End Source File
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\diathekemgr.h
# End Source File
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\gbfcgi.h
# End Source File
# Begin Source File

SOURCE=..\..\sword\apps\console\diatheke\thmlcgi.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
