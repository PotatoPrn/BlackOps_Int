#ifndef BLOPS_INTERNAL_HACKLIST_CPP
#define BLOPS_INTERNAL_HACKLIST_CPP

#include "HackList.h"
#include "Utils/MemUtils.h"
#include "Utils/HelperUtils.h"
#include "GraphicsUtils/Draw.h"


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

void CALLBACK InstaKillHack()
{
	int EntityCount = *(int*)(HackClass.ModuleBase + GOffset.EntCount);

	for (unsigned int i = 1; i < EntityCount + 1; i++)
	{
		PlayerEntity* Entity = *(PlayerEntity**)(HackClass.ModuleBase + GOffset.EntList + i * 0x8c); // Works

		if (FPSUtil::VerifyEntity(Entity) && HackClass.PlayerObject->TeamVal != Entity->TeamVal);
			Entity->Health = 1;
	}
}


void CALLBACK ESPHack()
{

	int EntityCount = *(int*)(HackClass.ModuleBase + GOffset.EntCount);

	for (unsigned int i = 0; i < EntityCount; i++)
	{
		PlayerEntity* Entity = *(PlayerEntity**)(HackClass.ModuleBase + GOffset.EntList + i * 0x8c);

		if (FPSUtil::VerifyEntity(Entity))
		{
			D3DCOLOR Color;

			if (Entity->TeamVal != HackClass.PlayerObject->TeamVal)
				Color = D3DCOLOR_ARGB(255, 255, 0, 0);
			else
				Color = D3DCOLOR_ARGB(255, 0, 255, 0);

			Vec2 EntPos2D;

			Vec3 EntPos3D = Entity->ZombiePos;


			if (FPSUtil::World2Screen(EntPos3D, EntPos2D)) /// ahhhhh
			{
				DrawLine(EntPos2D.x, EntPos2D.y, GHack.WindowWidth / 2, GHack.WindowHeight - 20, 2, Color);
			}
		}
	}
}

#endif //BLOPS_INTERNAL_HACKLIST_CPP