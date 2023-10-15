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

	for (unsigned int i = 1; i < MaxEnt + 1; i++)
	{
		PlayerEntity* Entity = *(PlayerEntity**)(HackClass.ModuleBase + GOffset.EntList + i * 0x8c); // Works

		if (FPSUtil::VerifyEntity(Entity) && HackClass.PlayerObject->TeamVal != Entity->TeamVal);
			Entity->Health = 1;
	}
}


void CALLBACK ESPHack()
{

	for (unsigned int i = 0; i < MaxEnt; i++)
	{
		PlayerEntity* Entity = *(PlayerEntity**)(HackClass.ModuleBase + GOffset.EntList + i * 0x8c);

		if (FPSUtil::VerifyEntity(Entity) && Entity->TeamVal != HackClass.PlayerObject->TeamVal)
		{
			D3DCOLOR Color;

			if (Entity->TeamVal != HackClass.PlayerObject->TeamVal)
				Color = D3DCOLOR_ARGB(255, 255, 0, 0);
			else
				Color = D3DCOLOR_ARGB(255, 0, 255, 0);

			Vec2 EntPos2D = {0, 0};

			Vec3 EntPos3D = Entity->ZombiePos;


			if (FPSUtil::World2Screen(EntPos3D, EntPos2D))
			{
				DrawLine(EntPos2D.x, EntPos2D.y, GHack.WindowWidth / 2, GHack.WindowHeight - 20, 2, Color);
			}
		}
	}
}


void CALLBACK RapidFire()
{
	if (HackClass.PlayerObject->LocalEnt->PlayerStatus == 0x50)
		HackClass.PlayerObject->LocalEnt->TimeToShoot = 10;
}


#endif //BLOPS_INTERNAL_HACKLIST_CPP