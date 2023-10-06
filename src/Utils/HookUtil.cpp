#ifndef BLOPS_INTERNAL_HOOKUTIL_CPP
#define BLOPS_INTERNAL_HOOKUTIL_CPP

#include "Utils/HookUtil.h"

#include <iostream>

bool Hook::Hook(char* Src, char* Dst, int Len)
{
	if (Len < 5)
		return FALSE;

	std::cout << (unsigned int)Src << std::endl << (unsigned int) Dst << std::endl;

	DWORD oProc;

	VirtualProtect(Src, Len, PAGE_EXECUTE_READWRITE, &oProc);

	// 0x90 = NOP?
	memset(Src, 0x90, Len); // Modify the .text section to jump to the new gateway created in the function below

	uintptr_t RelAddy = uintptr_t(Dst - Src - 5);

	*Src = (char)0xE9;

	*(uintptr_t*)(Src + 1) = (uintptr_t)RelAddy;

	VirtualProtect(Src, Len, oProc, &oProc);

	return TRUE;
}

char* Hook::TrampHook(char* Src, char* Dst, unsigned int Len)
{
	if (Len < 5)
		return 0;

	char* Gateway = (char*)VirtualAlloc(0, Len + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	memcpy(Gateway, Src, Len);

	uintptr_t GateRelAddy = (uintptr_t)(Src - Gateway - 5);

	*(Gateway + Len) = (char)0xE9;

	*(uintptr_t*)(Gateway + Len + 1) = GateRelAddy; // Create a gateway and add the bytes which return to the original routine

	if (Hook::Hook(Src, Dst, Len))
		return Gateway;
	else
		return nullptr;
}


#endif //BLOPS_INTERNAL_HOOKUTIL_CPP