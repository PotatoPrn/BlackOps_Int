#ifndef INTTEMPLATE_OFFSETS_H
#define INTTEMPLATE_OFFSETS_H

// Auto Padding
#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define DEFINE_MEMBER_N(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}


// Generic Structs
struct Vec3
{
	float x, y, z;

	Vec3 operator-(Vec3 Val)
	{
		return {x - Val.x, y - Val.y, z - Val.z};
	}
};

struct Vec2
{
	float x, y;
};


// Offsets Here
class LocalPlayerEnt
{
public:
	union
	{
		DEFINE_MEMBER_N(int, PlayerStatus, 0xc); // 0 = Normal, 2 = Crouch, 1 = Prone, 80 = Aimdown
		DEFINE_MEMBER_N(bool, IsRunning, 0xD); // 40 = Jump, 80 = Sprint
		DEFINE_MEMBER_N(Vec3, PlayerPos, 0x24);
		DEFINE_MEMBER_N(Vec3, Acceleration, 0x30);
		DEFINE_MEMBER_N(int, WeaponSpeed, 0x3c);
		DEFINE_MEMBER_N(int, TimeToShoot, 0x40);
		DEFINE_MEMBER_N(int, CurrentWeapon, 0x144);
		DEFINE_MEMBER_N(int, WeaponState, 0x158); // 6 = Shoot, 11 = Reload
		DEFINE_MEMBER_N(float, TimeToAimDown, 0x168);
		DEFINE_MEMBER_N(Vec3, ViewAngle, 0x180);
		DEFINE_MEMBER_N(Vec3, DamgeIndicatorAngle, 0x1B4);
	};
};

class PlayerEntity
{
public:
	union
	{
		DEFINE_MEMBER_N(int, TeamVal, 0xc);
		DEFINE_MEMBER_N(Vec3, ZombiePos, 0x18);
		DEFINE_MEMBER_N(LocalPlayerEnt*, LocalEnt, 0x13c);
		DEFINE_MEMBER_N(int, Health, 0x184);
	};
};

struct RefDef_t
{
	int x; // 0x0
	int y; // 0x4
	int Width; // 0x8
	int Height; // 0xa
	Vec2 FOV; // 0xc
	float FOVTotal; // 0x18
	char Junk[4]; // 0x1c
	Vec3 ViewOrigin; // 0x20
	char Junk2[8]; // 0x2c
	Vec3 ViewAxis[3]; // 0x34

};

struct GameOffset
{
public:
	uintptr_t GamePoints = 0x180A6C8;
	uintptr_t AmmoFunction = 0x2979B0;
	uintptr_t EntList = 0x17FBBF8;
	uintptr_t EntCount = 0x17FBC20;
	uintptr_t ViewMatrix = 0x7a6910;
	uintptr_t RefDef_O = 0x29CF5530;
};

extern GameOffset GOffset;


#endif //INTTEMPLATE_OFFSETS_H
