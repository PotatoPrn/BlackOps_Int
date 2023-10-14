#include "main.h"

// Setup Structs
GameHack HackClass;
EnabledHacks THacks;
GameOffset GOffset;
Graphics GHack;

// Directx9 Dummy Driver
LPDIRECT3DDEVICE9 pDevice = nullptr;
void* D3D9Device[119];
BYTE EndSceneByte[7]{ 0 };
tEndScene oEndScene = nullptr;


void APIENTRY hkEndScene(LPDIRECT3DDEVICE9 o_pDevice)
{
	if (!pDevice)
		pDevice = o_pDevice;

	DrawTextF("This is a Test Hack", GHack.WindowWidth / 2, GHack.WindowHeight - 60, D3DCOLOR_ARGB(255, 255, 255, 255));

	HackThread();

	oEndScene(pDevice);
}


// DLL Init Routine
void InitHack(HMODULE hModule)
{

	// Setup Output Console
	AllocConsole();
	FILE* fHandle;
	freopen_s(&fHandle, "CONOUT$", "w", stdout);

	/// Setup Hack hook Here
	if (InitD3D9(D3D9Device, sizeof(D3D9Device)))
	{
		// Cpy original Bytes to storage buffer
		memcpy_s(EndSceneByte, 7, (char*)D3D9Device[42], 7);

		// Setup Hack
		HackSetup();

		/// Patch EndScene to hack function
		oEndScene = (tEndScene)Hook::TrampHook((char*)D3D9Device[42], (char*)hkEndScene, 7);
	}


	while (!GetAsyncKeyState(VK_DELETE))
		Sleep(1);

	/// Fix patched bytes
	Mem::PatchByte((BYTE*)D3D9Device[42], EndSceneByte, 7);

	/// This sleep is essential when ejecting as it prevents actions from occurring while ejecting which causes the game to crash
	Sleep(1000);

	/// GHack.LineL->Release();
	GHack.FontF->Release();

	THacks.Destructor();


	/// Eject DLL
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
	do
	{
		HackClass.ModuleBase = (uintptr_t)GetModuleHandleA(HackClass.ModuleName);
	} while (HackClass.ModuleName == NULL);


	// Setup Console
	UI::ClearConsole();
	UI::SetupConsole();

	return;
}