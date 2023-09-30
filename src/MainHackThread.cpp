#ifndef INTTEMPLATE_HACKTHREAD_CPP
#define INTTEMPLATE_HACKTHREAD_CPP

#include "MainHackThread.h"

void HackThread()
{
	/// Modify PlayerObject
	HackClass.PlayerObject = *(PlayerEntity**)(HackClass.ModuleBase + 0);

	if (HackClass.PlayerObject)
	{
		while (true)
		{
			// Setup Detach Hotkey
			if (GetAsyncKeyState(VK_DELETE) & 1)
			{
				break;
			}











			Sleep(1);
		}
		// Return and Kill Console
		return;
	}
}

#endif //INTTEMPLATE_HACKTHREAD_CPP