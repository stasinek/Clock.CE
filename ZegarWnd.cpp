//-------------------------------------------------------------
#include "stdafx.h"
#include "ZegarWnd.h"
#include "UruchomWnd.h"
#include "BateriaWnd.h"
#include "AlarmWnd.h"
#include "KalendarzWnd.h"
#include "GetPrivateProfileStringW.h"
//-------------------------------------------------------------
/* all of definitions.h content */
//-------------------------------------------------------------
/// ZEGAREK 
//-------------------------------------------------------------
struct __zegar zegar;
struct __godzina godzina;
// Mesage handler for the About box.GetDialogBaseUnits
LRESULT CALLBACK ZegarWndProc(HWND this_hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

int wmId, wmEvent, i, u;
RECT rt, rt1;
wchar_t u_sh[3],ugroup_sh[5] = _T("");
wchar_t bitmap_file[32];
MENUITEMINFOW mii = { sizeof(MENUITEMINFOW) };
unsigned int idm;
TIME_ZONE_INFORMATION TimeZoneInformation;

	switch (message)
	{
		case WM_INITDIALOG:
			// trying to center the About dialog
			if (GetWindowRect(this_hDlg, &rt1)) {
				GetClientRect(GetParent(this_hDlg), &rt);
				// if the About box is larger than the physical screen
				SetWindowPos(this_hDlg, 0, rt.left, rt.top,
					rt.right-rt.left, rt.bottom-rt.top, SWP_NOZORDER);
			}
		GetTimeZoneInformation(&TimeZoneInformation);
		TimeZoneInformation.Bias = -60;
		SetTimeZoneInformation(&TimeZoneInformation);

		main_struct.uTimer[0] = SetTimer(this_hDlg,1111,
		1000,(TIMERPROC)ZegarTimerProc);
		main_struct.lf.lfHeight = 80;
		main_struct.lf.lfQuality =  CLEARTYPE_QUALITY;
		main_struct.lf.lfWeight = 700;
		main_struct.lf.lfCharSet = EASTEUROPE_CHARSET;
		strcpy((char*)main_struct.lf.lfFaceName,"Verdana");
		godzina.hf = CreateFontIndirect(&main_struct.lf);
		godzina.hfc = (COLORREF)0x000000;
		godzina.hb = CreateSolidBrush((COLORREF)0xFF0000);
		godzina.hp = CreatePen(PS_SOLID,1,(COLORREF)0x000000);
		GetClientRect(this_hDlg,&godzina.rt);
#ifndef CE
		godzina.rt.top -=24;
#endif
		godzina.rt.top = godzina.rt.top + 34;
		godzina.rt.bottom = godzina.rt.top + 80;
		godzina.rt.left = godzina.rt.left + 10;
		godzina.rt.right = godzina.rt.right - 10;


		main_struct.uTimer[2] = SetTimer(this_hDlg,2222,
			60000,(TIMERPROC)AlarmTimerProc);
		main_struct.lf.lfHeight = 34;
		main_struct.lf.lfQuality =  CLEARTYPE_QUALITY;
		main_struct.lf.lfWeight = 700; 
		main_struct.lf.lfCharSet = EASTEUROPE_CHARSET;
		strcpy((char*)main_struct.lf.lfFaceName,"Verdana"); 
		alarm.hf = CreateFontIndirect(&main_struct.lf);
		alarm.hfc = (COLORREF)0x000000;
		alarm.hb = CreateSolidBrush((COLORREF)0x000000);
		alarm.hp = CreatePen(PS_SOLID,1,(COLORREF)0x000000);

		alarm.localTime.wHour = 11;
		alarm.localTime.wMinute = 55;
		alarm.localTime.wSecond = 0;
		alarm.on = false;

		GetClientRect(this_hDlg,&alarm.rt);
		alarm.rt.top = godzina.rt.bottom + 10;
		alarm.rt.bottom = alarm.rt.top + 35;
		alarm.rt.left += 10 + 40;
		alarm.rt.right = alarm.rt.left + 150;

		alarm.hWnd =CreateWindowExW(NULL,
            L"BUTTON",
            L"^",
            WS_GROUP|WS_TABSTOP|WS_VISIBLE|
            WS_CHILD|BS_PUSHBUTTON,
            alarm.rt.left - 40,
            alarm.rt.top,
            35,
            35,
            this_hDlg,
            (HMENU)IDM_USTAWALARM,
            main_struct.hInst,
            NULL);
		SetWindowPos(alarm.hWnd,main_struct.hWnd,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

		main_struct.uTimer[1] = SetTimer(this_hDlg,3333,
			30000, (TIMERPROC)BateriaTimerProc); 
		main_struct.lf.lfHeight = 25; 
		main_struct.lf.lfQuality =  CLEARTYPE_QUALITY;
		main_struct.lf.lfWeight = 700; 
		main_struct.lf.lfCharSet = EASTEUROPE_CHARSET;
		strcpy((char*)main_struct.lf.lfFaceName,"Verdana"); 
		bateria.hf = CreateFontIndirect(&main_struct.lf);
		bateria.hfc = (COLORREF)0x000000;
		bateria.hb = CreateSolidBrush((COLORREF)0x00FF00);
		bateria.hp = CreatePen(PS_SOLID,1,(COLORREF)0x000000);


		GetClientRect(this_hDlg,&bateria.rt);
		bateria.rt.left    = bateria.rt.right - 70;
		bateria.rt.right  -= 10;
		bateria.rt.top     = godzina.rt.bottom + 10;
		bateria.rt.bottom  = bateria.rt.top + 25;

		bateria.hWnd =CreateWindowExW(NULL,
            L"BUTTON",
            L"=",
            WS_VISIBLE|
            WS_CHILD|BS_PUSHBUTTON,
            bateria.rt.left-30,
            bateria.rt.top,
            25,
            25,
            this_hDlg,
            (HMENU)IDM_BATERIA,
            main_struct.hInst,
            NULL);
		SetWindowPos(bateria.hWnd,alarm.hWnd,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
		GetClientRect(this_hDlg,&zegar.rt);
		
		main_struct.lf.lfHeight = 34; 
		main_struct.lf.lfQuality =  CLEARTYPE_QUALITY;
		main_struct.lf.lfWeight = 700; 
		main_struct.lf.lfCharSet = EASTEUROPE_CHARSET;
		strcpy((char*)main_struct.lf.lfFaceName,"Verdana"); 
		uruchom.hf = CreateFontIndirect(&main_struct.lf);
		uruchom.hfc = (COLORREF)0x000000;
		uruchom.hb = CreateSolidBrush((COLORREF)0x000000);
		uruchom.hp = CreatePen(PS_SOLID,1,(COLORREF)0x000000);

		GetClientRect(this_hDlg,&uruchom.rt);
		uruchom.rt.top = alarm.rt.bottom+10;
		uruchom.rt.bottom = uruchom.rt.top + 35;
		uruchom.rt.left  += 10 + 35 + 5;
		uruchom.rt.right -= 10;

		uruchom.selected = 0;
		uruchom.btn_hWnd =CreateWindowExW(NULL,
            L"BUTTON",
            _T("*"),
            WS_VISIBLE|
            WS_CHILD|BS_PUSHBUTTON,
            10,
            uruchom.rt.top,
            35,
            35,
            this_hDlg,
            (HMENU)URUCHOM_ID,
            main_struct.hInst,
            NULL);
		SetWindowPos(uruchom.hWnd,bateria.hWnd,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

		//Stworzenie parametru grupy [0],[1] etc. i odczyt tytu³u i œcie¿ki do programu z pliku ini 
//MessageBox(NULL,_itow(uruchom.rt.left,bitmap_file,10),_T("ERROR"),MB_OK);
//MessageBox(NULL,_itow(uruchom.rt.right,bitmap_file,10),_T("ERROR"),MB_OK);
				
for(u = 0; u<=4;u++)
	{
	wcscat(ugroup_sh,_T("["));
	wcscat(ugroup_sh,_itow(u,u_sh,10));
	wcscat(ugroup_sh,_T("]"));

	GetPrivateProfileStringW(ugroup_sh, _T("path"),_T("\\Windows\\explorer.exe"), (wchar_t*)uruchom.list[u].path, 100,(const wchar_t*)main_struct.profile_ini_path);
	GetPrivateProfileStringW(ugroup_sh, _T("bitmap_file"),_T("null.bmp"), bitmap_file, 100,(const wchar_t*)main_struct.profile_ini_path);
	GetPrivateProfileStringW(ugroup_sh, _T("text"),_T("brak definicji w pliku"), (wchar_t*)uruchom.list[u].text, 100,(const wchar_t*)main_struct.profile_ini_path);
	GetPrivateProfileStringW(ugroup_sh, _T("caption"),_T("??"), (wchar_t*)uruchom.list[u].caption, 100,(const wchar_t*)main_struct.profile_ini_path);
		
	GetModuleFileNameW(NULL,(wchar_t*)uruchom.list[u].bitmap_path,MAX_PATH);
    uruchom.list[u].lpbitmap_path = wcsrchr((wchar_t*)uruchom.list[u].bitmap_path,MAKEWORD('\\',0));
	if (uruchom.list[u].lpbitmap_path!=NULL) uruchom.list[u].lpbitmap_path[1]=MAKEWORD('\0',0);
	wcscat((wchar_t*)uruchom.list[u].bitmap_path,_T("bmp\\"));
	wcscat((wchar_t*)uruchom.list[u].bitmap_path,bitmap_file);
	uruchom.list[u].lpbitmap_path = (wchar_t*)&uruchom.list[u].bitmap_path;

	ugroup_sh[0]=NULL;


	uruchom.list[u].dc = CreateCompatibleDC(main_struct.dc);
	uruchom.list[u].hbitmap = SHLoadDIBitmap((wchar_t*)uruchom.list[u].bitmap_path);
	if (!uruchom.list[u].hbitmap)
	uruchom.list[u].hbitmap = (HBITMAP)LoadBitmap(main_struct.hInst,MAKEINTRESOURCE(IDB_U_NULL));
	if (uruchom.list[u].hbitmap)
	SelectObject(uruchom.list[u].dc,uruchom.list[u].hbitmap);

	if (u==0)idm = IDM_0;
	if (u==1)idm = IDM_1;
	if (u==2)idm = IDM_2;
	if (u==3)idm = IDM_3;
	if (u==4)idm = IDM_4;
	
	mii.fMask = MIIM_DATA;
	GetMenuItemInfoW(main_struct.hMenu, idm, FALSE, &mii);
	mii.dwTypeData = (wchar_t*)uruchom.list[u].text;
	SetMenuItemInfoW(main_struct.hMenu, idm, FALSE, &mii);

#define btnSPACING 5
	uruchom.list[u].hWnd =CreateWindowExW(NULL,
            L"BUTTON",
            (wchar_t*)uruchom.list[u].caption,
            WS_VISIBLE|
            WS_CHILD|BS_PUSHBUTTON,
            uruchom.rt.left +  u*((uruchom.rt.right - uruchom.rt.left - 4*btnSPACING)/5) + u*(btnSPACING),
            uruchom.rt.top,
            (uruchom.rt.right - uruchom.rt.left - 4*btnSPACING)/5,
            35,
            this_hDlg,
            (HMENU)idm,
            main_struct.hInst,
            NULL);
if (u==0)
	SetWindowPos(uruchom.list[u].hWnd,uruchom.hWnd,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
else
	SetWindowPos(uruchom.list[u].hWnd,uruchom.list[u-1].hWnd,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
}
		    return TRUE;
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				
				case URUCHOM_ID:
				if (!uruchom.hWnd)
					 uruchom.hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_URUCHOM, main_struct.hWnd, (DLGPROC)UruchomWndProc);
				break;
				case IDM_KALENDARZ:
				if (!kalendarz.hWnd)
					 kalendarz.hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_KALENDARZ, main_struct.hWnd, (DLGPROC)KalendarzWndProc);
				   break;
				case IDM_INFORMACJE:
				if (!bateria.opcje_hWnd)
					 bateria.opcje_hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_INFORMACJE, main_struct.hWnd, (DLGPROC)BateriaWndProc);
				   break;
				case IDM_USTAWALARM:
				if (!alarm.opcje_hWnd)
					 alarm.opcje_hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_USTAWALARM, main_struct.hWnd, (DLGPROC)AlarmWndProc);
				   break;
				case IDM_0:
					CreateProcessW((wchar_t*)uruchom.list[0].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[0].pi);
				   break;
				case IDM_1:
					CreateProcessW((wchar_t*)uruchom.list[1].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[0].pi);
				   break;
				case IDM_2:
					CreateProcessW((wchar_t*)uruchom.list[2].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[0].pi);
				   break;
				case IDM_3:
					CreateProcessW((wchar_t*)uruchom.list[3].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[0].pi);
				   break;
				case IDM_4:
					CreateProcessW((wchar_t*)uruchom.list[4].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[0].pi);
				   break;
				default:
				   return DefWindowProc(this_hDlg, message, wParam, lParam);
			       //break;
			}
			if ((LOWORD(wParam) == IDOK) || (LOWORD(wParam) == IDCANCEL))
			{
			DestroyWindow(this_hDlg);
				return TRUE;
			}
			break;
		case WM_PAINT:
			main_struct.dc = BeginPaint(this_hDlg,&main_struct.pt);
			BitBlt(main_struct.dc,0,0,bufor.rt.right,bufor.rt.bottom,bufor.dc,0,0,SRCCOPY);
			EndPaint(this_hDlg,&main_struct.pt);
			break;
		case WM_TIMER:
		    break;
		case WM_LBUTTONDOWN:
			
			if (GET_X_LPARAM(lParam) >= godzina.rt.left && GET_X_LPARAM(lParam) <= godzina.rt.right)
			if (GET_Y_LPARAM(lParam) >= godzina.rt.top  && GET_Y_LPARAM(lParam) <= godzina.rt.bottom)
				kalendarz.hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_KALENDARZ, main_struct.hWnd, (DLGPROC)KalendarzWndProc);
			if (GET_X_LPARAM(lParam) >= alarm.rt.left && GET_X_LPARAM(lParam) <= alarm.rt.right)
			if (GET_Y_LPARAM(lParam) >= alarm.rt.top  && GET_Y_LPARAM(lParam) <= alarm.rt.bottom)
				{alarm.on = !alarm.on; 
				if (alarm.on==true)	
					{ if (alarm.hb) DeleteObject(alarm.hb);
						alarm.hb = CreateSolidBrush((COLORREF)0x0000FF);
					}
				else 
					{ if (alarm.hb) DeleteObject(alarm.hb);
						alarm.hb = CreateSolidBrush((COLORREF)0x202020);
					}
				AlarmTimerProc(this_hDlg,NULL,NULL,0);
			}
			if (GET_X_LPARAM(lParam) >= uruchom.rt.left && GET_X_LPARAM(lParam) <= uruchom.rt.right)
			if (GET_Y_LPARAM(lParam) >= uruchom.rt.top  && GET_Y_LPARAM(lParam) <= uruchom.rt.bottom)
					CreateProcessW((wchar_t*)uruchom.list[uruchom.selected].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[uruchom.selected].pi);

			break;
		case WM_DESTROY:
			KillTimer(this_hDlg,main_struct.uTimer[0]);
			KillTimer(this_hDlg,main_struct.uTimer[1]);
			KillTimer(this_hDlg,main_struct.uTimer[2]);

			godzina.hWnd = NULL;
				DestroyWindow(godzina.hWnd);
			DeleteObject(godzina.hf);
			DeleteObject(godzina.hb);
			DeleteObject(godzina.hp);
			alarm.hWnd = NULL;
				DestroyWindow(alarm.hWnd);
			DeleteObject(alarm.hf);
			DeleteObject(alarm.hb);
			DeleteObject(alarm.hp);
			bateria.hWnd = NULL;
				DestroyWindow(bateria.hWnd);
			DeleteObject(bateria.hf);
			DeleteObject(bateria.hb);
			DeleteObject(bateria.hp);
		
			for (i = 0; i < 5;i++)
				if (uruchom.list[i].hbitmap) 
				{DeleteObject(uruchom.list[i].hbitmap);
				uruchom.list[i].hbitmap = NULL;
				DeleteObject(uruchom.list[i].dc);
				uruchom.list[i].dc = NULL;}
			
			DestroyWindow(uruchom.btn_hWnd);
			DestroyWindow(uruchom.hWnd);
			
			zegar.hWnd = NULL;
			DeleteObject(bufor.hbitmap); DeleteObject(bufor.dc);
			break;
		default:
			return DefWindowProc(this_hDlg, message, wParam, lParam);
	}
    return FALSE;
}
//---------------------------------------------------------------------------///
/// TIMERY
//---------------------------------------------------------------------------///

void CALLBACK ZegarTimerProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime )
{
	main_struct.global_Time = dwTime;
GetLocalTime(&godzina.localTime);

wcscpy(godzina.text,_T(""));
_itow(godzina.localTime.wHour,bufor.text,10);
if (wcslen(bufor.text)<=1) wcscat(godzina.text,_T("0"));
wcscat(godzina.text,bufor.text); 
wcscat(godzina.text,_T(":"));
_itow(godzina.localTime.wMinute,bufor.text,10);
if (wcslen(bufor.text)<=1) wcscat(godzina.text,_T("0"));
wcscat(godzina.text,bufor.text); 
wcscat(godzina.text,_T(":"));
_itow(godzina.localTime.wSecond,bufor.text,10);
if (wcslen(bufor.text)<=1) wcscat(godzina.text,_T("0"));
wcscat(godzina.text,bufor.text); 
wcscat(godzina.text,_T(""));

SetBkMode(bufor.dc, OPAQUE);
SelectObject(bufor.dc, godzina.hp);
SelectObject(bufor.dc, godzina.hb);
Rectangle(bufor.dc,godzina.rt.left,godzina.rt.top,godzina.rt.right,godzina.rt.bottom);
StretchBlt(bufor.dc,godzina.rt.left+1,godzina.rt.top+1,godzina.rt.right-godzina.rt.left-2,godzina.rt.bottom-godzina.rt.top-2, obrazek.dc, obrazek.bitmap.bmWidth * (godzina.rt.left+1) / (bufor.rt.right-bufor.rt.left),obrazek.bitmap.bmHeight * (godzina.rt.top+1) / (bufor.rt.bottom-bufor.rt.top), obrazek.bitmap.bmWidth * (godzina.rt.right-godzina.rt.left-2) / (bufor.rt.right-bufor.rt.left), obrazek.bitmap.bmHeight * (godzina.rt.bottom-godzina.rt.top-2) / (bufor.rt.bottom-bufor.rt.top), SRCPAINT);
SetBkMode(bufor.dc, TRANSPARENT);
SelectObject(bufor.dc, godzina.hf);
SetTextColor(bufor.dc, godzina.hfc);
DrawTextW(bufor.dc, godzina.text,wcslen(godzina.text), &godzina.rt,
		DT_SINGLELINE | DT_VCENTER | DT_CENTER);

/*	GetModuleFileName(NULL,bufor.text,MAX_PATH);
    bufor.lptext = wcsrchr(bufor.text,MAKEWORD('\\',0));
	if (bufor.lptext!=NULL) bufor.lptext[1]=MAKEWORD('\0',0);
	wcscat(bufor.text,TEXT("godzina.wav"));
	PlaySound(bufor.text,NULL,SND_ASYNC|SND_FILENAME);
*/

if (zegar.hWnd)
    RedrawWindow(zegar.hWnd, NULL, NULL, RDW_INVALIDATE);
}
//-------------------------------------------------------------