#ifndef INTTEMPLATE_HACKTHREAD_CPP
#define INTTEMPLATE_HACKTHREAD_CPP

#include "MainHackThread.h"

void HackThread()
{
	/// Modify PlayerObject
	HackClass.PlayerObject = *(PlayerEntity**)(HackClass.ModuleBase + 0x17FBBF8);

	if (HackClass.PlayerObject)
	{
		while (true)
		{

			// Setup Detach Hotkey
			if (GetAsyncKeyState(VK_DELETE) & 1)
				break;

			if (GetAsyncKeyState(VK_F10) & 1)
				THacks.T_Health = !THacks.T_Health;

			if (GetAsyncKeyState(VK_F9) & 1)
				THacks.T_Point = !THacks.T_Point;

			if (GetAsyncKeyState(VK_F8) & 1)
			{
				THacks.T_Ammo = !THacks.T_Ammo;
				AmmoHack();
			}






			/// Active Hacks
			if (THacks.T_Health)
				HealthHack();

			if (THacks.T_Point)
				PointHack();


			/// Display Commands...


			DbgPrint(F10, Invincible, THacks.T_Health);
			DbgPrint(F9, Infinite Point, THacks.T_Point);
			DbgPrint(F8, Infinite Ammo, THacks.T_Ammo);


			Sleep(1);

			UI::ClearConsole();
		}
		// Return and Kill Console
		return;
	}
}

#endif //INTTEMPLATE_HACKTHREAD_CPP