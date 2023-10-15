#ifndef INTTEMPLATE_MAINHACKTHREAD_H
#define INTTEMPLATE_MAINHACKTHREAD_H

#include "main.h"

// Print Define
#define DbgPrint(x, y, z) std::cout << "[" << #x << "]" << #y << " = " << (z ? "true" : "false") << "\n"
#define PosPrint(x, y, z1, z2, z3) std::cout << "[" << #x << "]" << #y << "  " << "X = " << z1 << " Y = " << z2 << " Z = " << z3 << "\n"


// Enabled Hacks Class, Ensure They are at false...
struct EnabledHacks
{
public:
	bool T_Health = false;
	bool T_Point = false;
	bool T_Ammo = false;
	bool T_IKill = false;
	bool T_ESP = false;
	bool T_RapidFire = false;
};

extern EnabledHacks THacks;


void HackThread();

#endif //INTTEMPLATE_MAINHACKTHREAD_H