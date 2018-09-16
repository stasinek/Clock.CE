#ifndef ZEGAREK_HDR
#define ZEGAREK_HDR

#ifndef UNICODE
	#define UNICODE
#endif

#ifndef _UNICODE
	#define _UNICODE
#endif

#ifndef __UNICODE
	#define __UNICODE
#endif

#if _MSC_VER > 1000
	#pragma once
#endif // _MSC_VER > 1000

/* all of include.h content */

#include "resource.h"
#ifndef __BORLANDC__
	#include "GetPrivateProfileStringW.h"
#endif
#include <commctrl.h>
#include <stdlib.h>
#include <string.h>
#include <Windowsx.h>
#include <Shellapi.h>

/* all of definitions content */

#ifndef _MSC_VER
	extern HBITMAP SHLoadDIBitmap(wchar_t *wchar);
#endif

#ifndef LR_DEFAULTSIZE
	#define LR_DEFAULTSIZE 0
#endif

#ifndef LR_LOADFROMFILE
	#define LR_LOADFROMFILE 16
#endif

#ifndef MAX_LOADSTRING
	#define MAX_LOADSTRING 256
#endif

#ifdef UNICODE
	#define _T(s) L##s
	#define TEXT(s) L##s
#else
	#define _T(s) s
	#define TEXT(s) s
#endif

extern struct __main_struct {
HINSTANCE		hInst;			// The current instance
HMENU			hMenu;			// The menu handle
HWND			hwndCB;			// The command bar handle
HWND			hWnd;			// main windows handle
DWORD global_Time;				// UNIX global time() since 1970 in miliseconds
LOGFONT lf;						// font template structure
HFONT hf;                       // handle to font used
RECT rt;                        // rectangle of main window
PAINTSTRUCT pt;               	// paint template struct
HDC dc;                         // handle to window canvas
UINT uTimer[10];                // timer
wchar_t profile_ini_path[MAX_LOADSTRING], *lpprofile_ini_path; // config file name
} main_struct;

////////////////////////
/// BUFOR
////////////////////////
extern struct __bufor {
RECT rt;						// bufor rectangle
HDC dc;                         // handle to bufor canvas created
HBITMAP hbitmap;                // handle to canvas bitmap
wchar_t text[MAX_LOADSTRING], *lptext; // text template bufor
} bufor;

////////////////////////
/// OBRAZEK
////////////////////////

extern struct __obrazek {
RECT rt;                        // wallpaper rectangle
HDC dc;                         // handle to canvas
HBITMAP hbitmap; BITMAP bitmap; // bitmap loaded and handle to it
SIZE size;
wchar_t text[MAX_LOADSTRING], *lptext; // text template bufor
} obrazek;

////////////////////////////////////////////////////////////////
////////////////QUEUE G£OWNEGO OKNA/////////////////////////////
////////////////////////////////////////////////////////////////
//
//
/* all of definitions.h content */
extern BOOL
InitMainInstance	(HINSTANCE, int);
extern ATOM
RegisterMainClassW	(HINSTANCE, LPCWSTR);
extern LRESULT CALLBACK
MainWndProc			(HWND, UINT, WPARAM, LPARAM);
////////////////////////////////////////////////////////////////
#endif

