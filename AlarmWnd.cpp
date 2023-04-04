//-------------------------------------------------------------
#include "stdafx.h"
#include "AlarmWnd.h"
#include "ZegarWnd.h"
/* all of definitions.h content */
//-------------------------------------------------------------
// ALARM      
//-------------------------------------------------------------
struct __alarm alarm;
// Mesage handler for the About box.
LRESULT CALLBACK AlarmWndProc(HWND this_hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
			alarm.opcje_hWnd = NULL;
			break;
		default:
			return DefWindowProc(this_hDlg, message, wParam, lParam);
	}
    return FALSE;
}
//-------------------------------------------------------------
/// Timer PROC
//-------------------------------------------------------------

void CALLBACK AlarmTimerProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime )
{
	main_struct.global_Time = dwTime;

wcscpy(alarm.text,_T(""));
_itow(alarm.localTime.wHour,bufor.text,10);
if (wcslen(bufor.text)<=1) wcscat(alarm.text,_T("0"));
wcscat(alarm.text,bufor.text); 
wcscat(alarm.text,_T(":"));
_itow(alarm.localTime.wMinute,bufor.text,10);
if (wcslen(bufor.text)<=1) wcscat(alarm.text,_T("0"));
wcscat(alarm.text,bufor.text); 
wcscat(alarm.text,_T(":"));
_itow(alarm.localTime.wSecond,bufor.text,10);
if (wcslen(bufor.text)<=1) wcscat(alarm.text,_T("0"));
wcscat(alarm.text,bufor.text); 
wcscat(alarm.text,_T(""));

SetBkMode(bufor.dc, OPAQUE);
SelectObject(bufor.dc, alarm.hp);
SelectObject(bufor.dc, alarm.hb);
Rectangle(bufor.dc,alarm.rt.left,alarm.rt.top,alarm.rt.right,alarm.rt.bottom);
BitBlt(bufor.dc,alarm.rt.left+1,alarm.rt.top+1,alarm.rt.right-alarm.rt.left-2,alarm.rt.bottom-alarm.rt.top-2,obrazek.dc,alarm.rt.left+1,alarm.rt.top+1,SRCPAINT);
SetBkMode(bufor.dc, TRANSPARENT);
SelectObject(bufor.dc, alarm.hf);
SetTextColor(bufor.dc, alarm.hfc);

DrawTextW(bufor.dc, alarm.text,wcslen(alarm.text), &alarm.rt,
			DT_SINGLELINE | DT_VCENTER | DT_CENTER);

bool activate;
activate = false;

if (alarm.localTime.wHour    < godzina.localTime.wHour)
activate = true;
if (alarm.localTime.wHour   == godzina.localTime.wHour)
if (alarm.localTime.wMinute  < godzina.localTime.wMinute)
activate = true;
if (alarm.localTime.wHour   == godzina.localTime.wHour)
if (alarm.localTime.wMinute == godzina.localTime.wMinute)
if (alarm.localTime.wSecond <= godzina.localTime.wSecond)
activate = true;

if (alarm.on==true && activate==true)
{
	GetModuleFileNameW(NULL,bufor.text,MAX_PATH);
    bufor.lptext = wcsrchr(bufor.text,MAKEWORD('\\',0));
	if (bufor.lptext!=NULL) bufor.lptext[1]=MAKEWORD('\0',0);
	wcscat(bufor.text,TEXT("wav\\alarm.wav"));
       //	PlaySound(bufor.text,NULL,SND_ASYNC|SND_FILENAME);
}

//if (zegar.hWnd)
//RedrawWindow(zegar.hWnd, NULL, NULL, RDW_INVALIDATE);
}
//-------------------------------------------------------------