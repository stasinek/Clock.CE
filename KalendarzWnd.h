/////
/// KALENDARZ
/////

#ifndef KalendarzWnd_h_
#define KalendarzWnd_h_

#include <commctrl.h>
#include <stdlib.h>
#include <string.h>
#include <Windowsx.h>

#include "ZegarekWinMain.h"

//-------------------------------------------------------------
/////KALENDARZ  ////
//-------------------------------------------------------------
//
//
/* all of definitions.h content */

extern struct __kalendarz {
HWND hWnd;
} kalendarz;

/////
// OKNO KALENDARZA
/////
extern LRESULT CALLBACK	KalendarzWndProc		(HWND, UINT, WPARAM, LPARAM);

#endif