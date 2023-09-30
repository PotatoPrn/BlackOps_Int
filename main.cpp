#include "main.h"

// Setup Structs
GameHack HackClass;
EnabledHacks THacks;
GameOffset GOffset;


// DLL Init Routine
void InitHack(HMODULE hModule)
{

	// Setup Output Console
	AllocConsole();
	FILE* fHandle;
	freopen_s(&fHandle, "CONOUT$", "w", stdout);

	// Begin Hack Routine
	HackSetup();

	// Eject DLL
	fclose(fHandle);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
}


// Start DLL
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)InitHack, hModule, 0, nullptr));
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


// Main HackThread
void HackSetup()
{
	// Setup Target DLL Name
	HackClass.ModuleName = "BlackOps.exe";


	// Setup Class Variables
	do {
		HackClass.ModuleBase = (uintptr_t)GetModuleHandleA(HackClass.ModuleName);
	} while (HackClass.ModuleName == NULL);


	// Setup Console
	UI::ClearConsole();
	UI::SetupConsole();

	// Main Hack Routine
	HackThread();

	return;
}