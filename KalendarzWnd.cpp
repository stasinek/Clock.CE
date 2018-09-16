#include "stdafx.h"
#include "KalendarzWnd.h"
/* all of definitions.h content */

struct __kalendarz kalendarz;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////KALENDARZ  /////////////////////////////
////////////////////////////////////////////////////////////////

// Mesage handler for the About box.
LRESULT CALLBACK KalendarzWndProc(HWND this_hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT rt, rt1;

	switch (message)
	{
		case WM_INITDIALOG:
			// trying to center the About dialog
			if (GetWindowRect(this_hDlg, &rt1)) {
				GetClientRect(GetParent(this_hDlg), &rt);
				// if the About box is larger than the physical screen 
				SetWindowPos(this_hDlg, HWND_TOP, rt.left, rt.top,
					rt.right-rt.left, rt.bottom-rt.top,NULL);
			}
			return TRUE;
		case WM_COMMAND:
			if ((LOWORD(wParam) == IDOK) || (LOWORD(wParam) == IDCANCEL))
			{
				DestroyWindow(this_hDlg);
				return TRUE;
			}
			break;
		case WM_DESTROY:
			kalendarz.hWnd = NULL;
			break;
		default:
			return DefWindowProc(this_hDlg, message, wParam, lParam);
	}
    return FALSE;
}
