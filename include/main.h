#ifndef INTTEMPLATE_MAIN_H
#define INTTEMPLATE_MAIN_H

// Standard C++ Headers
#include <iostream>
#include <vector>

// Windows Headers
#include <Windows.h>


// Local Headers
#include "Utils/MemUtils.h"
#include "Utils/UiUtils.h"
#include "MainHackThread.h"

// Offsets
#include "Offsets.h"

struct GameHack
{
public:
	const char* ModuleName;
	HWND Window;
	int WindowWidth, WindowLength;
	uintptr_t ModuleBase;
	PlayerEntity* PlayerObject;
};

extern GameHack HackClass;


void InitHack(HMODULE hModule);

void HackSetup();


#endif //INTTEMPLATE_MAIN_H
