//-------------------------------------------------------------
/// BATERIA
//-------------------------------------------------------------
#ifndef BateriaWnd_h_
#define BateriaWnd_h_
//-------------------------------------------------------------
#include <commctrl.h>
#include <stdlib.h>
#include <string.h>
#include <Windowsx.h>
#include "ZegarekWinMain.h"
//-------------------------------------------------------------
// WIN32 MISSING DEFINITIONS 
//-------------------------------------------------------------
#if defined(__WATCOM) || defined(__GNUC__)

#define BATTERY_CHEMISTRY_ALKALINE     0x01
#define BATTERY_CHEMISTRY_NICD         0x02
#define BATTERY_CHEMISTRY_NIMH         0x03
#define BATTERY_CHEMISTRY_LION         0x04
#define BATTERY_CHEMISTRY_LIPOLY       0x05
#define BATTERY_CHEMISTRY_ZINCAIR      0x06
#define BATTERY_CHEMISTRY_UNKNOWN      0xFF

#define TC_NORMAL 0
#define TC_HARDERR 1
#define TC_GP_TRAP 2
#define TC_SIGNAL 3

#define AC_LINE_OFFLINE 0x00
#define AC_LINE_ONLINE 0x01
#define AC_LINE_BACKUP_POWER 0x02
#define AC_LINE_UNKNOWN 0xff

#define BATTERY_FLAG_HIGH 0x01
#define BATTERY_FLAG_LOW 0x02
#define BATTERY_FLAG_CRITICAL 0x04
#define BATTERY_FLAG_CHARGING 0x08
#define BATTERY_FLAG_NO_BATTERY 0x80
#define BATTERY_FLAG_UNKNOWN 0xff

#define BATTERY_PERCENTAGE_UNKNOWN 0xff

#define BATTERY_LIFE_UNKNOWN 0xffffffff

#endif
#if defined(__WATCOM) || defined(__GNUC__) || defined(__BORLANDC__)

typedef struct _SYSTEM_POWER_STATUS_EX {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD BatteryFullLifeTime;
    BYTE Reserved2;
    BYTE BackupBatteryFlag;
    BYTE BackupBatteryLifePercent;
    BYTE Reserved3;
    DWORD BackupBatteryLifeTime;
    DWORD BackupBatteryFullLifeTime;
}   SYSTEM_POWER_STATUS_EX, *PSYSTEM_POWER_STATUS_EX, *LPSYSTEM_POWER_STATUS_EX;

typedef struct _SYSTEM_POWER_STATUS_EX2 {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD BatteryFullLifeTime;
    BYTE Reserved2;
    BYTE BackupBatteryFlag;
    BYTE BackupBatteryLifePercent;
    BYTE Reserved3;
    DWORD BackupBatteryLifeTime;
    DWORD BackupBatteryFullLifeTime;
    // Above here is old struct, below are new fields
    DWORD BatteryVoltage; 				// Reports Reading of battery voltage in millivolts (0..65535 mV)
    DWORD BatteryCurrent;				// Reports Instantaneous current drain (mA). 0..32767 for charge, 0 to -32768 for discharge
    DWORD BatteryAverageCurrent; 		// Reports short term average of device current drain (mA). 0..32767 for charge, 0 to -32768 for discharge
    DWORD BatteryAverageInterval;		// Reports time constant (mS) of integration used in reporting BatteryAverageCurrent
    DWORD BatterymAHourConsumed; 		// Reports long-term cumulative average DISCHARGE (mAH). Reset by charging or changing the batteries. 0 to 32767 mAH
    DWORD BatteryTemperature;			// Reports Battery temp in 0.1 degree C (-3276.8 to 3276.7 degrees C)
    DWORD BackupBatteryVoltage;			// Reports Reading of backup battery voltage
    BYTE  BatteryChemistry; 		    // See Chemistry defines above

    // New fields can be added below, but don't change any existing ones
}   SYSTEM_POWER_STATUS_EX2, *PSYSTEM_POWER_STATUS_EX2, *LPSYSTEM_POWER_STATUS_EX2;

// @CESYSGEN IF COREDLL_BATTERY
extern BOOL
WINAPI
GetSystemPowerStatusEx(
    PSYSTEM_POWER_STATUS_EX pSystemPowerStatusEx,
	BOOL fUpdate
    );

// Return value : 0 = fail.  Non-zero indicates length of returned data.
extern DWORD
WINAPI
GetSystemPowerStatusEx2(
    PSYSTEM_POWER_STATUS_EX2 pSystemPowerStatusEx2,
    DWORD dwLen,
	BOOL fUpdate
    );

#endif /* all of definitions.h content BORLAND WATCOMC GNUC */

extern struct __bateria{
_SYSTEM_POWER_STATUS_EX sps;
wchar_t text[MAX_LOADSTRING];
HFONT hf;
COLORREF hfc;
HBRUSH hb;
HPEN hp;
RECT rt;
HWND hWnd,opcje_hWnd;
} bateria;

extern LRESULT CALLBACK	BateriaWndProc			(HWND, UINT, WPARAM, LPARAM);
extern void CALLBACK BateriaTimerProc(HWND hwnd,UINT uMsg,UINT idEvent,DWORD dwTime );


#endif
