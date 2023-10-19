#ifndef BLOPS_INTERNAL_HACKLIST_CPP
#define BLOPS_INTERNAL_HACKLIST_CPP

#include "HackList.h"
#include "Utils/MemUtils.h"
#include "Utils/HelperUtils.h"
#include "GraphicsUtils/Draw.h"

#include <sstream>

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
	for (unsigned int i = 0; i < MaxEnt; i++)
	{
		PlayerEntity* Entity = *(PlayerEntity**)(HackClass.ModuleBase + GOffset.EntList + i * 0x8c);

		if (FPSUtil::VerifyEntity(Entity) && HackClass.PlayerObject->TeamVal != Entity->TeamVal &&
			Entity->Health != NULL)
		{
			Entity->Health = 1;
		}

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

			Vec2 EntPos2D, EntHead2D;

			Vec3 EntPos3D = Entity->ZombiePos;


			Vec3 EntPos3DHead = EntPos3D;
			EntPos3DHead += { 0, 0, 65 };


			if (FPSUtil::World2Screen(EntPos3D, EntPos2D))
			{
				DrawLine(EntPos2D.x, EntPos2D.y, GHack.WindowWidth / 2, GHack.WindowHeight - 20, 2, Color);

				if (FPSUtil::World2Screen(EntPos3DHead, EntHead2D))
				{
					DrawESPBox(EntPos2D, EntHead2D, 2,
							Color); /// todo Determine if enemy is a crawler, dog, or zombie as height is different
				}

				std::stringstream s1, s2;
				s1 << Entity->Health;
				s2 << i;
				std::string t1 = "HP: " + s1.str();
				std::string t2 = "Zombie: " + s2.str();
				char* HealthMsg = (char*)t1.c_str();
				char* ZombieIndex = (char*)t2.c_str();
				DrawTextF(HealthMsg, EntPos2D.x, EntPos2D.y, D3DCOLOR_ARGB(255, 255, 255, 255));
				DrawTextF(ZombieIndex, EntPos2D.x, EntPos2D.y + 1 * 18, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
		}
	}
}


void CALLBACK RapidFire()
{
	if (HackClass.PlayerObject->LocalEnt->PlayerStatus == 0x50)
		HackClass.PlayerObject->LocalEnt->TimeToShoot = 10;
}


void CALLBACK TestFunction()
{
	Vec3 Pos1 = *(Vec3*)(HackClass.ModuleBase + Enm1.Point1);
	Vec3 Pos2 = *(Vec3*)(HackClass.ModuleBase + Enm1.Point2);
	Vec3 Pos3 = *(Vec3*)(HackClass.ModuleBase + Enm1.Point3);
	Vec3 Pos4 = *(Vec3*)(HackClass.ModuleBase + Enm1.Point4);

	D3DCOLOR Color = D3DCOLOR_ARGB(255, 255, 255, 255);

	Vec2 Pos1_2D, Pos2_2D, Pos3_2D, Pos4_2D;

	FPSUtil::World2Screen(Pos1, Pos1_2D);
	FPSUtil::World2Screen(Pos2, Pos2_2D);
	FPSUtil::World2Screen(Pos3, Pos3_2D);
	FPSUtil::World2Screen(Pos4, Pos4_2D);


	DrawTextF("1", Pos1_2D.x, Pos1_2D.y, Color);
	DrawTextF("2", Pos2_2D.x, Pos2_2D.y, Color);
	DrawTextF("3", Pos3_2D.x, Pos3_2D.y, Color);
	DrawTextF("4", Pos4_2D.x, Pos4_2D.y, Color);
}

#endif //BLOPS_INTERNAL_HACKLIST_CPP