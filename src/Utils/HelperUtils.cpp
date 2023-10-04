#ifndef INTTEMPLATE_HELPERUTILS_CPP
#define INTTEMPLATE_HELPERUTILS_CPP

#include "Utils/HelperUtils.h"

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


#endif //INTTEMPLATE_HELPERUTILS_CPP