/////
/// ABOUT
/////

#ifndef AboutWnd_h_
#define AboutWnd_h_

#include <commctrl.h>
#include <stdlib.h>
#include <string.h>
#include <Windowsx.h>

#include "ZegarekWinMain.h"

//-------------------------------------------------------------
/////ABOUT      ////
//-------------------------------------------------------------
//
extern struct __about {
HWND hWnd;
}about;
/////
// OKNO POMOCY     
/////
extern LRESULT CALLBACK	AboutWndProc			(HWND, UINT, WPARAM, LPARAM);

#endif