#include "stdafx.h"
#include "BateriaWnd.h"
/* all of definitions.h content */
BOOL
WINAPI
GetSystemPowerStatusEx(
    PSYSTEM_POWER_STATUS_EX pSystemPowerStatusEx,
	BOOL fUpdate
    ) {return FALSE; }

// Return value : 0 = fail.  Non-zero indicates length of returned data.
DWORD
WINAPI
GetSystemPowerStatusEx2(
    PSYSTEM_POWER_STATUS_EX2 pSystemPowerStatusEx2,
    DWORD dwLen,
	BOOL fUpdate
    ) {return NULL; }

//-------------------------------------------------------------
/////BATERIA    ////
//-------------------------------------------------------------

struct __bateria bateria;

// Mesage handler for the About box.
LRESULT CALLBACK BateriaWndProc(HWND this_hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
			bateria.opcje_hWnd = NULL;
			break;
		default:
			return DefWindowProc(this_hDlg, message, wParam, lParam);
	}
    return FALSE;
}


void CALLBACK BateriaTimerProc(
HWND hWnd, 
UINT uMsg, 
UINT idEvent, 
DWORD dwTime )
{
main_struct.global_Time = dwTime;

if (GetSystemPowerStatusEx(&bateria.sps, TRUE))
{
_itow(bateria.sps.BatteryLifePercent,bufor.text,10); 
wcscat(bufor.text,_T("%"));

	SelectObject(bufor.dc, bateria.hf);
int color = ((bateria.sps.BatteryLifePercent * 0x0000FF00) / 100) | (((100 - bateria.sps.BatteryLifePercent) * 0x000000FF) / 100);

if (bateria.hb) DeleteObject(bateria.hb);
bateria.hb = CreateSolidBrush((COLORREF)color);

SetBkMode(bufor.dc, OPAQUE);
SelectObject(bufor.dc, bateria.hp);
SelectObject(bufor.dc, bateria.hb);
Rectangle(bufor.dc,bateria.rt.left,bateria.rt.top,bateria.rt.right,bateria.rt.bottom);
SelectObject(bufor.dc, bateria.hf);
SetTextColor(bufor.dc, bateria.hfc);
SetBkMode(bufor.dc, TRANSPARENT);
if (bateria.sps.ACLineStatus==1)
	DrawTextW(bufor.dc, _T("AC"),-1, &bateria.rt,
				DT_SINGLELINE | DT_VCENTER | DT_CENTER);
else
	DrawTextW(bufor.dc, bufor.text,wcslen(bufor.text), &bateria.rt,
				DT_SINGLELINE | DT_VCENTER | DT_CENTER);

if (bateria.sps.ACLineStatus==0 && bateria.sps.BatteryLifePercent <= 15)
	{
	GetModuleFileNameW(NULL,bufor.text,MAX_PATH);
    bufor.lptext = wcsrchr(bufor.text,MAKEWORD('\\',0));
	if (bufor.lptext!=NULL) bufor.lptext[1]=MAKEWORD('\0',0);
	wcscat(bufor.text,TEXT("wav\\lowbatt.wav"));
       //	PlaySound(bufor.text,NULL,SND_ASYNC|SND_FILENAME);
	}
if (bateria.sps.ACLineStatus==0 && bateria.sps.BatteryLifePercent <= 5)
	{
	// powinien uœpiæ zegary i uœpiæ nawigacje
	}
}
//if (zegar.hWnd)
//RedrawWindow(zegar.hWnd, NULL, NULL, RDW_INVALIDATE);


//Brightess(100);
}
