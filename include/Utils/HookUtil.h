#ifndef BLOPS_INTERNAL_HOOKUTIL_H
#define BLOPS_INTERNAL_HOOKUTIL_H

#include <Windows.h>

namespace Hook
{
	bool Hook(char* Src, char* Dst, int Len);

	char* TrampHook(char* Src, char* Dst, unsigned int Len);
}
#endif //BLOPS_INTERNAL_HOOKUTIL_H