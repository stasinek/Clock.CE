#if !defined(GetPrivateProfileStringW_H)
#define GetPrivateProfileStringW_H
#if defined(__WATCOM) || defined(___MSC_VER) ||  defined(VER_PLATFORM_WIN32_CE)
	#include <windows.h>
	#define IN
	#define OUT
	DWORD WINAPI GetPrivateProfileStringW(
		IN LPCWSTR lpAppName,
		IN LPCWSTR lpKeyName,
		IN LPCWSTR lpDefault,
		OUT LPWSTR lpReturnedString,
		IN DWORD nSize,
		IN LPCWSTR lpFileName
    );
	#endif
#endif
