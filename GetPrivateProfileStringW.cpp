#include "stdafx.h"
#include "GetPrivateProfileStringW.h"
//#ifdef _MSC_VER || __BORLANDC__

#ifndef UNICODE
#define UNICODE
#endif

#ifdef UNICODE
#ifndef _T
#define _T(s) L##s
#endif
#ifndef TEXT
#define TEXT(s) L##s
#endif
#else
#define _T(s) s
#define TEXT(s) s
#endif

DWORD
WINAPI
GetPrivateProfileStringW(
    IN LPCWSTR lpAppName,
    IN LPCWSTR lpKeyName,
    IN LPCWSTR lpDefault,
    OUT LPWSTR lpReturnedString,
    IN DWORD nSize,
    IN LPCWSTR lpFileName
    )
{
//As far as I know the corrent UNICODE line ending on windows platform is \r\n,
//that is 0x000D000A and ansii 0x0D0A
//so properly encoded UTF16 file should have a BOM, FF FE in the first 2 byte positions.
//function supports only unicode 16-bit files

	HANDLE hfile = CreateFileW(lpFileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,NULL,NULL);
    if (hfile==INVALID_HANDLE_VALUE)
        {//MessageBox(NULL,_T("Nie można otworzyć pliku?!"),lpFileName,MB_OK);
         return 1;}
    unsigned long i = 0,b = GetFileSize(hfile,NULL), e = b/2, br, l = 0;
    wchar_t* lpBuffer = new  wchar_t[e+1];
    wchar_t* linia = new wchar_t[100];
	bool found = false, foundsection = false;

    if (e<=2)
        {//MessageBox(NULL,_T("Plik jest pusty!"),lpFileName,MB_OK);
         return 1;}
    if (!ReadFile(hfile,lpBuffer,b,&br,NULL))
        {//MessageBox(NULL,_T("Z jakiegoś powodu nie można odczytać pliku?!"),lpFileName,MB_OK);
		 return 1;}
    if (lpBuffer[i++]!=0xFEFF)
        {MessageBoxW(NULL,_T("Ten program wspiera pliki .ini UTF16 - zmień kodowanie w notatniku"),lpFileName,MB_OK);
		 return 1;}

    for (; i < e; )
	{
        linia[l] = lpBuffer[i];

		if (found==false && foundsection==false) {
            if ((lpBuffer[i]=='\r' && lpBuffer[i+1]=='\n') || (lpBuffer[i]=='\r' && lpBuffer[i+1]=='\0'))
			    {linia[l]=MAKEWORD('\0',0);
			     if (wcscmp(linia,lpAppName)==0) foundsection = true;
                             l = 0; i+=2;  //przejdź do nowej linii po znalezieniu sekcji
			     continue;
			    }
		}
        if (found==false && foundsection==TRUE) {
            if ((lpBuffer[i]=='\r' && lpBuffer[i+1]=='\n') || (lpBuffer[i]=='\r' && lpBuffer[i+1]=='\0'))
			   {linia[l]=MAKEWORD('\0',0);
			    l = 0; i+=2;
			    continue;
			}
			if (linia[l]==' ' || linia[l]=='=')
			   {linia[l]=MAKEWORD('\0',0);
			    if (wcscmp(linia,lpKeyName)==0) found = true;
			    l = 0; i+=1;
                            continue;
			}
	        if (linia[l]=='[' || linia[l]==']')
               {wcscpy(lpReturnedString,lpDefault);
                break;
            }
        }
		if (found==TRUE  && foundsection==TRUE) {
            if ((lpBuffer[i]=='\r' && lpBuffer[i+1]=='\n') || (lpBuffer[i]=='\r' && lpBuffer[i+1]=='\0') || i==e-1)
			   {linia[l]=MAKEWORD('\0',0);
			    wcscpy(lpReturnedString,linia);
                l = 0;
			    break;
			}
        }
          i++; l++;
	}
	CloseHandle(hfile);
	delete lpBuffer, linia;
	if (found==false)
                {wcscpy(lpReturnedString,lpDefault);
                 return 1;
                 }
return 0;
}

//#endif
