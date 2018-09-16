////////////////////////
/// ZEGAR
////////////////////////

#ifndef ZegarWnd_h_
#define ZegarWnd_h_

#include <commctrl.h>
#include <stdlib.h>
#include <string.h>
#include <Windowsx.h>

#include "Zegarek.h"

////////////////////////////////////////////////////////////////
////////////////////////ZEGAREK    /////////////////////////////
////////////////////////////////////////////////////////////////
//
//
/* all of definitions.h content */

extern struct __zegar {
HFONT hf;
HPEN hp;
HBRUSH hb;
RECT rt;
HWND hWnd,opcje_hWnd;
}
zegar;

////////////////////////
/// godzina
////////////////////////

extern struct __godzina {
SYSTEMTIME localTime;
wchar_t text[MAX_LOADSTRING];
HFONT hf;
COLORREF hfc;
HBRUSH hb;
HPEN hp;
RECT rt;
HWND hWnd,opcje_hWnd;
} godzina;


extern LRESULT CALLBACK	ZegarWndProc		(HWND, UINT, WPARAM, LPARAM);
extern void CALLBACK ZegarTimerProc(HWND hwnd,UINT uMsg,UINT idEvent,DWORD dwTime );

#endif