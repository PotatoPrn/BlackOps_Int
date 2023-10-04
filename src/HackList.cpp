#ifndef BLOPS_INTERNAL_HACKLIST_CPP
#define BLOPS_INTERNAL_HACKLIST_CPP

#include "HackList.h"
#include "Utils/MemUtils.h"
#include "Utils/HelperUtils.h"


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

void CALLBACK TestingHack()
{
	int EntityCount = *(int*)(HackClass.ModuleBase + GOffset.EntCount);

	std::cout << EntityCount << "\n";

	for (unsigned int i = 1; i < EntityCount + 1; i++)
	{
		PlayerEntity* Entity = *(PlayerEntity**)(HackClass.ModuleBase + GOffset.EntList + i * 0x8c); // Works

		if (FPSUtil::VerifyEntity(Entity) && HackClass.PlayerObject->PosTeam != Entity->PosTeam);
		std::cout << Entity->Health << "\n";
	}
}

#endif //BLOPS_INTERNAL_HACKLIST_CPP