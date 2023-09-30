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
};


// Offsets Here

class PlayerEntity
{
public:
	union
	{
		DEFINE_MEMBER_N(Vec3, PlayerPos, 0x18);
		DEFINE_MEMBER_N(Vec3, ViewAngle, 0x3c);
		DEFINE_MEMBER_N(int, Health, 0x184);
		DEFINE_MEMBER_N(int, PosTeam, 0x774);

	};
};

struct GameOffset
{
public:
	uintptr_t GamePoints = 0x180A6C8;
	uintptr_t AmmoFunction = 0x2979B0;
};

extern GameOffset GOffset;


#endif //INTTEMPLATE_OFFSETS_H
