#include "stdafx.h"
#include "UruchomWnd.h"
/* all of definitions.h content */

//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
/////URUCHOM    ////
//-------------------------------------------------------------
struct __uruchom uruchom;

// Mesage handler for the Uruchom box.
LRESULT CALLBACK UruchomWndProc(HWND this_hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT rt, rt1;
HDC dc;
	switch (message)
	{
		case WM_INITDIALOG:
			// trying to center the About dialog
uruchom.selected = 0;
			
			if (GetWindowRect(this_hDlg, &rt1)) {
				GetWindowRect(GetParent(this_hDlg), &rt);
				// if the About box is larger than the physical screen 
				SetWindowPos(this_hDlg, HWND_TOP, rt.left, rt.top,
					rt.right-rt.left, rt.bottom-rt.top, NULL);
			}

			
			
			return TRUE;
		case WM_COMMAND:
			if ((LOWORD(wParam) == IDOK))
			{
			CreateProcessW((const wchar_t*)uruchom.list[uruchom.selected].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[uruchom.selected].pi);
			
			}
			if ((LOWORD(wParam) == IDOK) || (LOWORD(wParam) == IDCANCEL))
			{
			uruchom.hWnd = NULL;
				DestroyWindow(this_hDlg);
				return TRUE;
			}
			if ((LOWORD(wParam) == IDNEXT))
			{
			uruchom.selected++;
			if(uruchom.selected>4) uruchom.selected=0;
			dc = BeginPaint(this_hDlg,&main_struct.pt);
BitBlt(dc,0,0,180,55,uruchom.list[uruchom.selected].dc,0,0,SRCPAINT);
			EndPaint(this_hDlg,&main_struct.pt);

			}	
			break;
		case WM_PAINT:
			
			break;
		default:
			return DefWindowProc(this_hDlg, message, wParam, lParam);
	}
    return FALSE;
}
