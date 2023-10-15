#ifndef INTTEMPLATE_HELPERUTILS_CPP
#define INTTEMPLATE_HELPERUTILS_CPP

#include "Utils/HelperUtils.h"
#include <math.h>


float FPSUtil::DistanceDif(Vec3 Dst, Vec3 Src)
{
	float Distance;

	Distance = sqrtf(
			pow(Dst.x - Src.x, 2) +
			pow(Dst.y - Src.y, 2) +
			pow(Dst.z - Src.z, 2));

	return Distance;
}

bool FPSUtil::VerifyEntity(PlayerEntity* Entity)
{
	if (Entity == NULL)
		return FALSE;

	if (Entity->Health <= 0)
		return FALSE;

	return TRUE;
}

float FPSUtil::DotProduct(Vec3 Dst, Vec3 Src)
{
	return Dst.x * Src.x + Dst.y * Src.y + Dst.z * Src.z;
}


bool FPSUtil::World2Screen(Vec3 Pos, Vec2& Screen)
{
	Vec3 Transform, vLocal;

	vLocal = Pos - HackClass.RefDef_C->ViewOrigin;

	Transform.x = DotProduct(vLocal, HackClass.RefDef_C->ViewAxis[1]); // X (L & R)
	Transform.y = DotProduct(vLocal, HackClass.RefDef_C->ViewAxis[2]); // Y (U & D)
	Transform.z = DotProduct(vLocal, HackClass.RefDef_C->ViewAxis[0]); // Z (F & B)

	if (Transform.z < 0.01f) // Ensure the camera isnt behind the player
		return false;

	Screen.x = ((HackClass.RefDef_C->Width / 2) * (1 - (Transform.x / HackClass.RefDef_C->FOV.x / Transform.z)));
	Screen.y = ((HackClass.RefDef_C->Height / 2) * (1 - (Transform.y / HackClass.RefDef_C->FOV.y / Transform.z)));

	return true;
}

#endif //INTTEMPLATE_HELPERUTILS_CPP