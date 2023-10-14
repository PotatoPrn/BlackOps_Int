#ifndef INTTEMPLATE_PROCESSUTILS_CPP
#define INTTEMPLATE_PROCESSUTILS_CPP

#include "Utils/ProcessUtils.h"


/// Get Current Window's Handle ID
HWND GetDeviceWindow()
{
	GHack.Window = NULL;

	EnumWindows(EnumWind, NULL);

	RECT Size;
	GetWindowRect(GHack.Window, &Size);
	GHack.WindowWidth = Size.right - Size.left;
	GHack.WindowHeight = Size.bottom - Size.top;

	return GHack.Window;
}

BOOL CALLBACK EnumWind(HWND Handle, LPARAM lp)
{
	DWORD ProcID;
	GetWindowThreadProcessId(Handle, &ProcID);

	if (GetCurrentProcessId() != ProcID)
		return TRUE;

	if (Handle == GetConsoleWindow())
		return TRUE;

	GHack.Window = Handle;
	return FALSE;
}


#endif //INTTEMPLATE_PROCESSUTILS_CPP