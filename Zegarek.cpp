// Zegarek.cpp : Defines the entry point for the application.
//
#include "stdafx.h"
#include "Zegarek.h"
#include "ZegarWnd.h"
#include "AlarmWnd.h"
#include "KalendarzWnd.h"
#include "UruchomWnd.h"
#include "BateriaWnd.h"
#include "AboutWnd.h"

#ifndef _MSC_VER
HBITMAP SHLoadDIBitmap(wchar_t *wchar) {
return (HBITMAP)LoadImageW(GetModuleHandle(NULL),
                                       wchar,
                                       IMAGE_BITMAP,
                                       LR_DEFAULTSIZE,
                                       LR_DEFAULTSIZE,
                                       LR_LOADFROMFILE);
}
#endif
////////////////////////////////////////////////////////////////

struct __main_struct main_struct;
struct __obrazek obrazek;
struct __bufor bufor;

////////////////////////////////////////////////////////////////
/////////////////////PROCEDURA WEJŚCIA/////////////////////////
////////////////////////////////////////////////////////////////

#ifdef __GNUC__
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
#else
int WINAPI  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd)
#endif
{
	MSG msg;
	HACCEL hAccelTable;
	// Perform application initialization:
	if (InitMainInstance (hInstance, nShowCmd)==FALSE) {
	MessageBoxW(NULL,TEXT("Nie mozna utworzyc okna programu"),TEXT("sstsoft->zegarek"),MB_OK);
		return FALSE;
	}
	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_ZEGAREK);
	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))  {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
						TranslateMessage(&msg); DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//  FUNCTION: MainInitInstance(HANDLE, int)
//  PURPOSE: Saves instance handle and creates main window
//  COMMENTS:
//  In this function, we save the instance handle in a global variable and
//  create and display the main program window.
//
BOOL InitMainInstance(HINSTANCE hInstance, int nCmdShow)
{
	wchar_t	szTitle[MAX_LOADSTRING];			// The title bar text
	wchar_t	szWindowClass[MAX_LOADSTRING];		// The window class name

	main_struct.hInst = hInstance;		// Store instance handle in our global variable
	// Initialize global strings
	LoadStringW(hInstance, IDC_ZEGAREK, szWindowClass, MAX_LOADSTRING);
	// Register Window Class
	RegisterMainClassW(hInstance, szWindowClass);
	// Create Main Window
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	HWND this_hWnd = CreateWindowW(szWindowClass, szTitle, WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (!this_hWnd) { return FALSE;}
	else main_struct.hWnd = this_hWnd;

	GetModuleFileNameW(NULL,main_struct.profile_ini_path,MAX_PATH);
    main_struct.lpprofile_ini_path = wcsrchr(main_struct.profile_ini_path,MAKEWORD('.',0));
	if (main_struct.lpprofile_ini_path!=NULL) main_struct.lpprofile_ini_path[1]=MAKEWORD('\0',0);
	wcscat(main_struct.profile_ini_path,TEXT("ini"));
	main_struct.lpprofile_ini_path = (wchar_t*)&main_struct.profile_ini_path;

	main_struct.dc = GetDC(this_hWnd);

	GetClientRect(this_hWnd,&bufor.rt);
	bufor.dc = CreateCompatibleDC(main_struct.dc);
	bufor.hbitmap = CreateCompatibleBitmap(main_struct.dc, bufor.rt.right-bufor.rt.left, bufor.rt.bottom-bufor.rt.top);
	if (bufor.hbitmap)
		SelectObject(bufor.dc,bufor.hbitmap);
	else { MessageBoxW(this_hWnd,_T("SelectObject(bufor.dc,bufor.hbitmap);"),_T("ERROR"),MB_OK);
		return FALSE;}

	GetClientRect(this_hWnd,&obrazek.rt);
	obrazek.dc = CreateCompatibleDC(main_struct.dc);
	GetModuleFileNameW(NULL,obrazek.text,MAX_PATH);
    obrazek.lptext = wcsrchr(obrazek.text,MAKEWORD('\\',0));
	if (obrazek.lptext!=NULL) obrazek.lptext[1]=MAKEWORD('\0',0);
	wcscat(obrazek.text,TEXT("bmp\\desktop.bmp"));
    obrazek.hbitmap = SHLoadDIBitmap(obrazek.text);
	if (!obrazek.hbitmap)
	obrazek.hbitmap = (HBITMAP)LoadBitmap(main_struct.hInst,MAKEINTRESOURCE(IDB_WINDOWSCE));
	if (obrazek.hbitmap)
	SelectObject(obrazek.dc,obrazek.hbitmap);
	else { MessageBoxW(this_hWnd,_T("SelectObject(obrazek.dc,obrazek.bitmap);"),_T("ERROR"),MB_OK);
		return FALSE;}

	GetObject(obrazek.hbitmap, sizeof(obrazek.bitmap), &obrazek.bitmap );
	StretchBlt(bufor.dc,0,0,bufor.rt.right,bufor.rt.bottom,obrazek.dc,0,0, obrazek.bitmap.bmWidth, obrazek.bitmap.bmHeight, SRCCOPY);

	bateria.opcje_hWnd = NULL;
	kalendarz.hWnd = NULL;
	about.hWnd = NULL;
	zegar.hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_ZEGAR, this_hWnd, (DLGPROC)ZegarWndProc);
	if (!zegar.hWnd)
	{ MessageBoxW(this_hWnd,_T("zegar.hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_ZEGAR, this_hWnd, (DLGPROC)Zegar);"),_T("ERROR"),MB_OK);
		return FALSE;}

	ZegarTimerProc(zegar.hWnd,NULL,NULL,0);
		 BateriaTimerProc(bateria.opcje_hWnd,NULL,NULL,0);
	AlarmTimerProc(zegar.hWnd,NULL,NULL,0);

	ShowWindow(this_hWnd, nCmdShow); UpdateWindow(this_hWnd);
	//if (main_struct.hwndCB)
	//	CommandBar_Show(main_struct.hwndCB, TRUE);
	return TRUE;
}
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//  FUNCTION: MainRegisterClass()
//  PURPOSE: Registers the window class.
//  COMMENTS:
//  It is important to call this function so that the application
//  will get 'well formed' small icons associated with it.
//
ATOM RegisterMainClassW(HINSTANCE hInstance, LPCWSTR szWindowClass)
{
	WNDCLASSW	wc;

    wc.style			= CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc		= (WNDPROC)MainWndProc;
    wc.cbClsExtra		= 0;
    wc.cbWndExtra		= 0;
    wc.hInstance		= hInstance;
    wc.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ZEGAREK));
    wc.hCursor			= 0;
    wc.hbrBackground	= (HBRUSH) COLOR_BACKGROUND;
    wc.lpszMenuName		= 0;
    wc.lpszClassName	= szWindowClass;

	return RegisterClassW(&wc);
}

////////////////////////////////////////////////////////////////
///////MESSAGE QUEUE GŁOWNEGO OKNA/////////////////////////////
////////////////////////////////////////////////////////////////

//  FUNCTION: MainWndProc(HWND, unsigned, WORD, LONG)
//  PURPOSE:  Processes messages for the main window.
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
LRESULT CALLBACK MainWndProc(HWND this_hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;

	switch (message)
	{
		case WM_COMMAND:

			wmId    = LOWORD(wParam);
			wmEvent = HIWORD(wParam);
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_KALENDARZ:
				if (!kalendarz.hWnd)
					 kalendarz.hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_KALENDARZ, this_hWnd, (DLGPROC)KalendarzWndProc);
				   break;
				case IDM_USTAWALARM:
				if (!alarm.opcje_hWnd)
					 alarm.opcje_hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_USTAWALARM, this_hWnd, (DLGPROC)AlarmWndProc);
				   break;
				case IDM_INFORMACJE:
				if (!bateria.opcje_hWnd)
					 bateria.opcje_hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_INFORMACJE, this_hWnd, (DLGPROC)BateriaWndProc);
				   break;
				case IDM_HELP_ABOUT:
				if (!about.hWnd)
					 about.hWnd = CreateDialog(main_struct.hInst, (LPCTSTR)IDD_ABOUTBOX, this_hWnd, (DLGPROC)AboutWndProc);
				   break;
				case IDM_0:
					CreateProcessW((const wchar_t*)uruchom.list[0].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[0].pi);
				   break;
				case IDM_1:
					CreateProcessW((const wchar_t*)uruchom.list[1].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[1].pi);
				   break;
				case IDM_2:
					CreateProcessW((const wchar_t*)uruchom.list[2].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[2].pi);
				   break;
				case IDM_3:
					CreateProcessW((const wchar_t*)uruchom.list[3].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[3].pi);
				   break;
				case IDM_4:
					CreateProcessW((const wchar_t*)uruchom.list[4].path,NULL,NULL,NULL,NULL,CREATE_NEW_CONSOLE,NULL,NULL,NULL,&uruchom.list[4].pi);
				   break;
				default:
				   return DefWindowProc(this_hWnd, message, wParam, lParam);
			}
			break;
		case WM_CREATE:
#ifndef __BORLANDC__
//			main_struct.hwndCB = CommandBar_Create(main_struct.hInst, this_hWnd, 1);
//			CommandBar_InsertMenubar(main_struct.hwndCB, main_struct.hInst, IDM_MENU, 0);
//			CommandBar_AddAdornments(main_struct.hwndCB, 0, 0);
//#define SHGetMenu(hWndMB) (HMENU)SendMessage((hWndMB),
//      SHCMBM_GETMENU, (WPARAM)0, (LPARAM)0);
//	main_struct.hMenu =  CommandBar_GetMenu(main_struct.hwndCB, IDM_0);
	//		main_struct.hMenu =  SHGetMenu(main_struct.hWnd);
#endif

			break;
		case WM_PAINT:
			break;
		case WM_DESTROY:
#ifndef __BORLANDC__
//			CommandBar_Destroy(main_struct.hwndCB);
#endif
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(this_hWnd, message, wParam, lParam);
   }
   return false;
}
#define IOCTL_BKL_SET_INTENSITY CTL_CODE(BACKLIGHT_DEVICE_ID, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)

/*
		GetPrivateProfileStringW(_T("[0]"), _T("path"),_T("\\Windows\\explorer.exe"), uruchom[0].path, 100,main_struct.profile_ini_path);
		GetPrivateProfileStringW(_T("[0]"), _T("text"),_T("0"), uruchom[0].text, 100,main_struct.profile_ini_path);
		uruchom[0].hWnd =CreateWindowEx(NULL,
            L"BUTTON",
            uruchom[0].text,
            WS_TABSTOP|WS_VISIBLE|
            WS_CHILD|BS_PUSHBUTTON,
            (zegar.rt.right - zegar.rt.left - 20)/5 * 0 + 10 + (0*10)/5,
            alarm.rt.bottom+10,
            (zegar.rt.right - zegar.rt.left - 20)/5 - 10,
            35,
            this_hDlg,
            (HMENU)IDM_0,
            main_struct.hInst,
            NULL);
		SetWindowPos(uruchom[0].hWnd,HWND_BOTTOM,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);



	GetPrivateProfileStringW(_T("[1]"), _T("path"),_T("\\Windows\\explorer.exe"), uruchom[1].path, 100,main_struct.profile_ini_path);
	GetPrivateProfileStringW(_T("[1]"), _T("text"),_T("1"), uruchom[1].text, 100,main_struct.profile_ini_path);
	uruchom[1].hWnd =CreateWindowEx(NULL,
            L"BUTTON",
            uruchom[1].text,
            WS_TABSTOP|WS_VISIBLE|
            WS_CHILD|BS_PUSHBUTTON,
            (zegar.rt.right - zegar.rt.left - 20)/5 * 1 + 10 + (1*10)/5,
            alarm.rt.bottom+10,
            (zegar.rt.right - zegar.rt.left - 20)/5 - 10,
            35,
            this_hDlg,
            (HMENU)IDM_1,
            main_struct.hInst,
            NULL);
	SetWindowPos(uruchom[1].hWnd,HWND_BOTTOM,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

	GetPrivateProfileStringW(_T("[2]"), _T("path"),_T("\\Windows\\explorer.exe"), uruchom[2].path, 100,main_struct.profile_ini_path);
	GetPrivateProfileStringW(_T("[2]"), _T("text"),_T("2"), uruchom[2].text, 100,main_struct.profile_ini_path);
	uruchom[2].hWnd =CreateWindowEx(NULL,
            L"BUTTON",
            uruchom[2].text,
            WS_TABSTOP|WS_VISIBLE|
            WS_CHILD|BS_PUSHBUTTON,
            (zegar.rt.right - zegar.rt.left - 20)/5 * 2 + 10 + (2*10)/5,
            alarm.rt.bottom+10,
            (zegar.rt.right - zegar.rt.left - 20)/5 - 10,
            35,
            this_hDlg,
            (HMENU)IDM_2,
            main_struct.hInst,
            NULL);
	SetWindowPos(uruchom[2].hWnd,HWND_BOTTOM,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

	GetPrivateProfileStringW(_T("[3]"), _T("path"),_T("\\Windows\\explorer.exe"), uruchom[3].path, 100,main_struct.profile_ini_path);
	GetPrivateProfileStringW(_T("[3]"), _T("text"),_T("3"), uruchom[3].text, 100,main_struct.profile_ini_path);
	uruchom[3].hWnd =CreateWindowEx(NULL,
            L"BUTTON",
            uruchom[3].text,
            WS_TABSTOP|WS_VISIBLE|
            WS_CHILD|BS_PUSHBUTTON,
            (zegar.rt.right - zegar.rt.left - 20)/5 * 3 + 10 + (3*10)/5,
            alarm.rt.bottom+10,
            (zegar.rt.right - zegar.rt.left - 20)/5 - 10,
            35,
            this_hDlg,
            (HMENU)IDM_3,
            main_struct.hInst,
            NULL);
	SetWindowPos(uruchom[3].hWnd,HWND_BOTTOM,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

	GetPrivateProfileStringW(_T("[4]"), _T("path"),_T("\\Windows\\explorer.exe"), uruchom[4].path, 100,main_struct.profile_ini_path);
	GetPrivateProfileStringW(_T("[4]"), _T("text"),_T("4"), uruchom[4].text, 100,main_struct.profile_ini_path);
	uruchom[4].hWnd =CreateWindowEx(NULL,
            L"BUTTON",
            uruchom[4].text,
            WS_TABSTOP|WS_VISIBLE|
            WS_CHILD|BS_PUSHBUTTON,
            (zegar.rt.right - zegar.rt.left - 20)/5 * 4 + 10 + (4*10)/5,
            alarm.rt.bottom+10,
            (zegar.rt.right - zegar.rt.left - 20)/5 - 10,
            35,
            this_hDlg,
            (HMENU)IDM_4,
            main_struct.hInst,
            NULL);
	SetWindowPos(uruchom[4].hWnd,HWND_BOTTOM,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

*/
/*
void static  Brightness(BYTE bBrightNess)
{
    bool bRet = FALSE;
    HANDLE hDevBKL;    
    DWORD dwPercent=(DWORD)bBrightNess * 6.4;          //3;
    hDevBKL = CreateFile(_T("BKL1:"),
                         GENERIC_READ|GENERIC_WRITE,
                         FILE_SHARE_READ|FILE_SHARE_WRITE,
                         NULL,
                         OPEN_ALWAYS,
                         0,
                         0);
        
    bRet = DeviceIoControl(hDevBKL,
                       IOCTL_BKL_SET_INTENSITY,
                       &dwPercent,
                       sizeof(dwPercent),
                       NULL,
                       0,
                       NULL,
                       NULL);
        
 
    if(!bRet)
    {
            SetLastError(GetLastError());
	}
}
*/
