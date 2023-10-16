#ifndef INTTEMPLATE_HACKTHREAD_CPP
#define INTTEMPLATE_HACKTHREAD_CPP

#include "MainHackThread.h"

/// Teleportation Variables
Vec3 SavedPos = { 0, 0, 0 };
Vec3 PrevPos = { 0, 0, 0 };

void HackThread()
{
	/// Get Required Offsets
	HackClass.PlayerObject = *(PlayerEntity**)(HackClass.ModuleBase + 0x17FBBF8);
	HackClass.RefDef_C = (RefDef_t*)0x29CF5530;


	if (HackClass.PlayerObject)
	{

		/// Show Menu
		if (GetAsyncKeyState(VK_F1) & 1)
			THacks.T_ShowMenu = !THacks.T_ShowMenu;

		/// Prevent Hacks from toggling when menu is disabled
		if (THacks.T_ShowMenu)
		{
			/// Increase Health and Continuous Write
			if (GetAsyncKeyState(VK_F10) & 1)
				THacks.T_Health = !THacks.T_Health;

			/// Increase Points and continuous Write
			if (GetAsyncKeyState(VK_F9) & 1)
				THacks.T_Point = !THacks.T_Point;

			/// Enable Ammo Hack
			if (GetAsyncKeyState(VK_F8) & 1)
			{
				THacks.T_Ammo = !THacks.T_Ammo;
				AmmoHack();
			}

			/// Save Current Coords
			if (GetAsyncKeyState(VK_F7) & 1)
				SavedPos = HackClass.PlayerObject->LocalEnt->PlayerPos;

			/// If Alt is Engaged while F6, Teleport to Prev Pos, Else Teleport to New Pos
			if (GetAsyncKeyState(VK_F6) & 1)
			{
				if (!GetAsyncKeyState(VK_MENU) & 1)
				{
					PrevPos = HackClass.PlayerObject->LocalEnt->PlayerPos;
					HackClass.PlayerObject->LocalEnt->PlayerPos = SavedPos;
				}
				else
					HackClass.PlayerObject->LocalEnt->PlayerPos = PrevPos;
			}

			/// Disabled as it breaks the game :/
			//if (GetAsyncKeyState(VK_F5) & 1)
				//THacks.T_IKill = !THacks.T_IKill;

			/// ESP Hack
			if (GetAsyncKeyState(VK_F4) & 1)
				THacks.T_ESP = !THacks.T_ESP;

			if (GetAsyncKeyState(VK_F3) & 1)
				THacks.T_RapidFire = !THacks.T_RapidFire;
		}


		/// Active Hacks
		// Continuous Write
		if (THacks.T_Health)
			HealthHack();

		// Byte Patching
		if (THacks.T_Point)
			PointHack();

		if (THacks.T_IKill)
			InstaKillHack();

		if (THacks.T_ESP)
			ESPHack();

		if (THacks.T_RapidFire)
			RapidFire();




		/// Display Commands...
		DbgPrint(F10, Invincible, THacks.T_Health);
		DbgPrint(F9, Infinite Point, THacks.T_Point);
		DbgPrint(F8, Infinite Ammo, THacks.T_Ammo);
		PosPrint(F7, Save Waypoint >, SavedPos.x, SavedPos.y, SavedPos.z);
		DbgPrint(F6 / Shift + F6, Teleport to waypoint / Return to Prev Waypoint, 0);
		DbgPrint(F5, InstaKill Hack, THacks.T_IKill);
		DbgPrint(F4, ESP Hack, THacks.T_ESP);
		DbgPrint(F3, RapidFire, THacks.T_RapidFire);


		UI::ClearConsole();

		// Return and Kill Console
		return;
	}
}

#endif //INTTEMPLATE_HACKTHREAD_CPP