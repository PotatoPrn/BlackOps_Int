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

	if (Entity->Health == 0)
		return FALSE;

	return TRUE;
}

float FPSUtil::DotProduct(Vec3 Dst, Vec3 Src)
{
	return Dst.x * Src.x + Dst.y * Src.y + Dst.z * Src.z;
}


bool FPSUtil::World2Screen(Vec3 Pos, Vec2& Screen)
{
	/// Game uses 3 x 4 view matrix
	int Width = HackClass.RefDef_C->Width / 2;
	int Height = HackClass.RefDef_C->Height / 2;


	Vec3 Transform;
	Vec3 LRAxis = HackClass.RefDef_C->ViewAxis[0]; // Left & Right
	Vec3 UDAxis = HackClass.RefDef_C->ViewAxis[1]; // Up & Down
	Vec3 FBAxis = HackClass.RefDef_C->ViewAxis[2]; // Forward & Backwards

	Vec2 Fov;
	Fov.x = HackClass.RefDef_C->FOV.x;
	Fov.y = HackClass.RefDef_C->FOV.y;

	Transform = (HackClass.RefDef_C->ViewOrigin - Pos);

	float z = FPSUtil::DotProduct(Transform, LRAxis);

	if (z <= 0.01f)
		return false;

	Screen.x = Width - DotProduct(Transform, UDAxis) * Width / (z * Fov.x);
	Screen.y = Height - DotProduct(Transform, FBAxis) * Height / (z * Fov.y);


	return true;

}

#endif //INTTEMPLATE_HELPERUTILS_CPP