////////////////////////
/// URUCHOM
////////////////////////

#ifndef UruchomWnd_h_
#define UruchomWnd_h_

#define URUCHOM_ID 88

#include <commctrl.h>
#include <stdlib.h>
#include <string.h>
#include <Windowsx.h>
#include "Zegarek.h"

////////////////////////////////////////////////////////////////
////////////////////////URUCHOM    /////////////////////////////
////////////////////////////////////////////////////////////////

extern struct __uruchom {
HWND hWnd, btn_hWnd;

struct { wchar_t path[MAX_LOADSTRING], *lppath;
wchar_t bitmap_path[MAX_LOADSTRING], *lpbitmap_path;
wchar_t caption[MAX_LOADSTRING], *lpcaption;
wchar_t text[MAX_LOADSTRING], *lptext;
unsigned short enabled;
 PROCESS_INFORMATION pi;
 HBITMAP hbitmap;
 HDC dc;
 HWND hWnd;
}list[5];

HFONT hf;
COLORREF hfc;
HBRUSH hb;
HPEN hp;
RECT rt;
unsigned short selected;
} uruchom;

////////////////////////
// OKNO URUCHAMIANIA     
////////////////////////
extern LRESULT CALLBACK	UruchomWndProc			(HWND, UINT, WPARAM, LPARAM);
#endif