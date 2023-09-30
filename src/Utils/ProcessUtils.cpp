#ifndef INTTEMPLATE_PROCESSUTILS_CPP
#define INTTEMPLATE_PROCESSUTILS_CPP

#include "Utils/ProcessUtils.h"


/// Get Current Window's Handle ID
HWND GetDeviceWindow()
{
	HackClass.Window = NULL;

	EnumWindows(EnumWind, NULL);

	RECT Size;
	GetWindowRect(HackClass.Window, &Size);
	HackClass.WindowWidth = Size.right - Size.left;
	HackClass.WindowLength = Size.bottom - Size.top;

	return HackClass.Window;
}

BOOL CALLBACK EnumWind(HWND Handle, LPARAM lp)
{
	DWORD ProcID;
	GetWindowThreadProcessId(Handle, &ProcID);

	if (GetCurrentProcessId() != ProcID)
		return TRUE;

	if (Handle == GetConsoleWindow())
		return TRUE;

	HackClass.Window = Handle;
	return FALSE;
}


#endif //INTTEMPLATE_PROCESSUTILS_CPP