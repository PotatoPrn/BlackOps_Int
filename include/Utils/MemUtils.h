#ifndef INTTEMPLATE_MEMUTILS_H
#define INTTEMPLATE_MEMUTILS_H

#include <vector>

#include <Windows.h>
#include <Psapi.h>

namespace Mem
{
	uintptr_t FindDMAAddy(uintptr_t AddrPtr, std::vector<unsigned int> MultiLevelOffset);

	uintptr_t PatternScanModule(char* Module, char* Pattern, char* Mask);
}

char* BasicPatternScan(char* Base, size_t Size, char* Pattern, char* Mask);

char* InternalScanWrapper(char* Begin, size_t Size, char* Pattern, char* Mask);


#endif //INTTEMPLATE_MEMUTILS_H
