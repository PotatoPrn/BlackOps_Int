#ifndef INTTEMPLATE_HELPERUTILS_H
#define INTTEMPLATE_HELPERUTILS_H

#include "main.h"

#define PI 3.141592653589

namespace FPSUtil
{
	float DistanceDif(Vec3 Dst, Vec3 Src);

	bool VerifyEntity(PlayerEntity* Entity);

	bool World2Screen(Vec3 Pos, Vec2& Screen);

	float DotProduct(Vec3 Dst, Vec3 Src);
}


#endif //INTTEMPLATE_HELPERUTILS_H