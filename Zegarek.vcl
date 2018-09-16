<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Zegarek - Win32 (WCE ARMV4) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"ARMV4Rel/Zegarek.res" /d UNDER_CE=400 /d _WIN32_WCE=400 /d "NDEBUG" /d "UNICODE" /d "_UNICODE" /d "WCE_PLATFORM_STANDARDSDK" /d "ARM" /d "_ARM_" /d "ARMV4" /r "C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\Zegarek.rc"" 
Creating temporary file "C:\TEMP\RSP858.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=400 /D "WCE_PLATFORM_STANDARDSDK" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=400 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /FR"ARMV4Rel/" /Fp"ARMV4Rel/Zegarek.pch" /Yu"stdafx.h" /Fo"ARMV4Rel/" /O2 /MC /c 
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\AboutWnd.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\AlarmWnd.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\BateriaWnd.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\GetPrivateProfileStringW.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\KalendarzWnd.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\sstsoft_button.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\UruchomWnd.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\Zegarek.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\ZegarWnd.cpp"
]
Creating command line "clarm.exe @C:\TEMP\RSP858.tmp" 
Creating temporary file "C:\TEMP\RSP859.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=400 /D "WCE_PLATFORM_STANDARDSDK" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=400 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /FR"ARMV4Rel/" /Fp"ARMV4Rel/Zegarek.pch" /Yc"stdafx.h" /Fo"ARMV4Rel/" /O2 /MC /c 
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\TEMP\RSP859.tmp" 
Creating temporary file "C:\TEMP\RSP85A.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:no /pdb:"ARMV4Rel/Zegarek.pdb" /map:"ARMV4Rel/Zegarek.map" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4Rel/Zegarek.exe" /subsystem:windowsce,4.00 /align:"4096" /MACHINE:ARM 
".\ARMV4Rel\AboutWnd.obj"
".\ARMV4Rel\AlarmWnd.obj"
".\ARMV4Rel\BateriaWnd.obj"
".\ARMV4Rel\GetPrivateProfileStringW.obj"
".\ARMV4Rel\KalendarzWnd.obj"
".\ARMV4Rel\sstsoft_button.obj"
".\ARMV4Rel\StdAfx.obj"
".\ARMV4Rel\UruchomWnd.obj"
".\ARMV4Rel\Zegarek.obj"
".\ARMV4Rel\ZegarWnd.obj"
".\ARMV4Rel\Zegarek.res"
]
Creating command line "link.exe @C:\TEMP\RSP85A.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
AboutWnd.cpp
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(51) : warning C4005: '_T' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\tchar.h(37) : see previous definition of '_T'
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(52) : warning C4005: 'TEXT' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\winnt.h(218) : see previous definition of 'TEXT'
AlarmWnd.cpp
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(51) : warning C4005: '_T' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\tchar.h(37) : see previous definition of '_T'
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(52) : warning C4005: 'TEXT' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\winnt.h(218) : see previous definition of 'TEXT'
BateriaWnd.cpp
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(51) : warning C4005: '_T' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\tchar.h(37) : see previous definition of '_T'
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(52) : warning C4005: 'TEXT' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\winnt.h(218) : see previous definition of 'TEXT'
GetPrivateProfileStringW.cpp
KalendarzWnd.cpp
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(51) : warning C4005: '_T' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\tchar.h(37) : see previous definition of '_T'
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(52) : warning C4005: 'TEXT' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\winnt.h(218) : see previous definition of 'TEXT'
sstsoft_button.cpp
UruchomWnd.cpp
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(51) : warning C4005: '_T' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\tchar.h(37) : see previous definition of '_T'
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(52) : warning C4005: 'TEXT' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\winnt.h(218) : see previous definition of 'TEXT'
Zegarek.cpp
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(51) : warning C4005: '_T' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\tchar.h(37) : see previous definition of '_T'
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(52) : warning C4005: 'TEXT' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\winnt.h(218) : see previous definition of 'TEXT'
ZegarWnd.cpp
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(51) : warning C4005: '_T' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\tchar.h(37) : see previous definition of '_T'
c:\documents and settings\stasiek.tc12\my documents\my projects\ce\zegarek\zegarek.h(52) : warning C4005: 'TEXT' : macro redefinition
        c:\program files\windows ce tools\wce400\standardsdk\include\armv4\winnt.h(218) : see previous definition of 'TEXT'
Generating Code...
Linking...
Creating temporary file "C:\TEMP\RSP85D.tmp" with contents
[
/nologo /o"ARMV4Rel/Zegarek.bsc" 
".\ARMV4Rel\StdAfx.sbr"
".\ARMV4Rel\AboutWnd.sbr"
".\ARMV4Rel\AlarmWnd.sbr"
".\ARMV4Rel\BateriaWnd.sbr"
".\ARMV4Rel\GetPrivateProfileStringW.sbr"
".\ARMV4Rel\KalendarzWnd.sbr"
".\ARMV4Rel\sstsoft_button.sbr"
".\ARMV4Rel\UruchomWnd.sbr"
".\ARMV4Rel\Zegarek.sbr"
".\ARMV4Rel\ZegarWnd.sbr"]
Creating command line "bscmake.exe @C:\TEMP\RSP85D.tmp"
Creating browse info file...
<h3>Output Window</h3>
Creating temporary file "C:\TEMP\RSP85E.bat" with contents
[
@echo off
rapi.bat
]
Creating command line "C:\TEMP\RSP85E.bat"
RAPI
The system cannot find the path specified.
Error executing c:\windows\system32\cmd.exe.



<h3>Results</h3>
Zegarek.exe - 1 error(s), 14 warning(s)
</pre>
</body>
</html>
