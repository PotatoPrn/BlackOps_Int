#ifndef BLOPS_INTERNAL_HACKLIST_CPP
#define BLOPS_INTERNAL_HACKLIST_CPP

#include "HackList.h"
#include "Utils/MemUtils.h"


void CALLBACK HealthHack()
{
	HackClass.PlayerObject->Health = 1000;
}

void CALLBACK PointHack()
{
	*(int*)(HackClass.ModuleBase + GOffset.GamePoints) = 13337;
}


void CALLBACK AmmoHack()
{
	if (!THacks.T_Ammo)
		Mem::PatchByte((BYTE*)(HackClass.ModuleBase + GOffset.AmmoFunction), (BYTE*)"\x55", 1);
	else
		Mem::PatchByte((BYTE*)(HackClass.ModuleBase + GOffset.AmmoFunction), (BYTE*)"\xC3", 1);
}

#endif //BLOPS_INTERNAL_HACKLIST_CPP