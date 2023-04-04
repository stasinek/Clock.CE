#ifndef GetPrivateProfileStringW_h
#define GetPrivateProfileStringW_h
#include <windows.h>
#define IN
#define OUT
#ifdef __BORLANDC__ || ___MSC_VER
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
