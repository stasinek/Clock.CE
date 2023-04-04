/////
/// ALARM
/////

#ifndef AlarmWnd_h_
#define AlarmWnd_h_

#include <commctrl.h>
#include <stdlib.h>
#include <string.h>
#include <Windowsx.h>

#include "ZegarekWinMain.h"

//-------------------------------------------------------------
/////ALARM      ////
//-------------------------------------------------------------
//
//
/* all of definitions.h content */

extern struct __alarm {
bool on;
SYSTEMTIME localTime;
wchar_t text[MAX_LOADSTRING];
HFONT hf;
COLORREF hfc;
HBRUSH hb;
HPEN hp;
RECT rt;
HWND hWnd,opcje_hWnd;
} alarm;

extern LRESULT CALLBACK	AlarmWndProc			(HWND, UINT, WPARAM, LPARAM);
extern void CALLBACK AlarmTimerProc(HWND hwnd,UINT uMsg,UINT idEvent,DWORD dwTime );

#endif