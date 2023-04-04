<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Zegarek - Win32 (WCE emulator) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\TEMP\RSP35E.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=400 /D "WCE_PLATFORM_STANDARDSDK" /D "_i386_" /D UNDER_CE=400 /D "i_386_" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "NDEBUG" /FR"emulatorRel/" /Fp"emulatorRel/Zegarek.pch" /YX /Fo"emulatorRel/" /Gs8192 /GF /O2 /c 
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\AboutWnd.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\AlarmWnd.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\GetPrivateProfileStringW.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\KalendarzWnd.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\sstsoft_button.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\UruchomWnd.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\ZegarekWinMain.cpp"
"C:\Documents and Settings\stasiek.TC12\My Documents\My Projects\CE\ZEGAREK\ZegarWnd.cpp"
]
Creating command line "cl.exe @C:\TEMP\RSP35E.tmp" 
Creating temporary file "C:\TEMP\RSP35F.tmp" with contents
[
commctrl.lib coredll.lib corelibc.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:no /pdb:"emulatorRel/Zegarek.pdb" /nodefaultlib:"OLDNAMES.lib" /nodefaultlib:libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /out:"emulatorRel/Zegarek.exe" /subsystem:windowsce,4.00 /MACHINE:IX86 
".\emulatorRel\AboutWnd.obj"
".\emulatorRel\AlarmWnd.obj"
".\emulatorRel\BateriaWnd.obj"
".\emulatorRel\GetPrivateProfileStringW.obj"
".\emulatorRel\KalendarzWnd.obj"
".\emulatorRel\sstsoft_button.obj"
".\emulatorRel\StdAfx.obj"
".\emulatorRel\UruchomWnd.obj"
".\emulatorRel\ZegarekWinMain.obj"
".\emulatorRel\ZegarWnd.obj"
".\emulatorRel\Zegarek.res"
]
Creating command line "link.exe @C:\TEMP\RSP35F.tmp"
<h3>Output Window</h3>
Compiling...
AboutWnd.cpp
AlarmWnd.cpp
GetPrivateProfileStringW.cpp
KalendarzWnd.cpp
sstsoft_button.cpp
UruchomWnd.cpp
ZegarekWinMain.cpp
ZegarWnd.cpp
Linking...
Creating temporary file "C:\TEMP\RSP362.tmp" with contents
[
/nologo /o"emulatorRel/Zegarek.bsc" 
".\emulatorRel\AboutWnd.sbr"
".\emulatorRel\AlarmWnd.sbr"
".\emulatorRel\BateriaWnd.sbr"
".\emulatorRel\GetPrivateProfileStringW.sbr"
".\emulatorRel\KalendarzWnd.sbr"
".\emulatorRel\sstsoft_button.sbr"
".\emulatorRel\StdAfx.sbr"
".\emulatorRel\UruchomWnd.sbr"
".\emulatorRel\ZegarekWinMain.sbr"
".\emulatorRel\ZegarWnd.sbr"]
Creating command line "bscmake.exe @C:\TEMP\RSP362.tmp"
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
Zegarek.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
