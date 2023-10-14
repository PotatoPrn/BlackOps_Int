#ifndef INTTEMPLATE_MAIN_H
#define INTTEMPLATE_MAIN_H

// Standard C++ Headers
#include <iostream>
#include <vector>

// Windows Headers
#include <Windows.h>


// Graphics LIbrary
#include "d3d9.h"
#include "d3dx9.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern LPDIRECT3DDEVICE9 pDevice;

// Local Headers
#include "Utils/MemUtils.h"
#include "Utils/UiUtils.h"
#include "MainHackThread.h"
#include "HackList.h"
#include "GraphicsUtils/Directx.h"
#include "Utils/HookUtil.h"
#include "GraphicsUtils/Draw.h"

// Offsets
#include "Offsets.h"

struct GameHack
{
public:
	const char* ModuleName;
	uintptr_t ModuleBase;
	PlayerEntity* PlayerObject;
	RefDef_t* RefDef_C;
};

extern GameHack HackClass;

struct Graphics
{
public:
	HWND Window;
	int WindowWidth, WindowHeight;
	ID3DXLine* LineL;
	ID3DXFont* FontF;
};

extern Graphics GHack;




void InitHack(HMODULE hModule);

void HackSetup();


#endif //INTTEMPLATE_MAIN_H
