#ifndef INTTEMPLATE_OFFSETS_H
#define INTTEMPLATE_OFFSETS_H

// Auto Padding
#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define DEFINE_MEMBER_N(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}


// Generic Structs
class Vec3
{
public:
    Vec3(void)
    {
        Invalidate();
    }
    Vec3(float X, float Y, float Z)
    {
        x = X;
        y = Y;
        z = Z;
    }
    Vec3(const float* clr)
    {
        x = clr[0];
        y = clr[1];
        z = clr[2];
    }

    void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
    {
        x = ix; y = iy; z = iz;
    }
    bool IsValid() const
    {
        return std::isfinite(x) && std::isfinite(y) && std::isfinite(z);
    }
    void Invalidate()
    {
        x = y = z = std::numeric_limits<float>::infinity();
    }

    float& operator[](int i)
    {
        return ((float*)this)[i];
    }
    float operator[](int i) const
    {
        return ((float*)this)[i];
    }

    void Zero()
    {
        x = y = z = 0.0f;
    }

    bool operator==(const Vec3& src) const
    {
        return (src.x == x) && (src.y == y) && (src.z == z);
    }
    bool operator!=(const Vec3& src) const
    {
        return (src.x != x) || (src.y != y) || (src.z != z);
    }

    Vec3& operator+=(const Vec3& v)
    {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }
    Vec3& operator-=(const Vec3& v)
    {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }
    Vec3& operator*=(float fl)
    {
        x *= fl;
        y *= fl;
        z *= fl;
        return *this;
    }
    Vec3& operator*=(const Vec3& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }
    Vec3& operator/=(const Vec3& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }
    Vec3& operator+=(float fl)
    {
        x += fl;
        y += fl;
        z += fl;
        return *this;
    }
    Vec3& operator/=(float fl)
    {
        x /= fl;
        y /= fl;
        z /= fl;
        return *this;
    }
    Vec3& operator-=(float fl)
    {
        x -= fl;
        y -= fl;
        z -= fl;
        return *this;
    }

    void NormalizeInPlace()
    {
        *this = Normalized();
    }
    Vec3 Normalized() const
    {
        Vec3 res = *this;
        float l = res.Length();
        if (l != 0.0f) {
            res /= l;
        }
        else {
            res.x = res.y = res.z = 0.0f;
        }
        return res;
    }

    float DistTo(const Vec3& vOther) const
    {
        Vec3 delta;

        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;

        return delta.Length();
    }
    float DistToSqr(const Vec3& vOther) const
    {
        Vec3 delta;

        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;

        return delta.LengthSqr();
    }
    float Dot(const Vec3& vOther) const
    {
        return (x * vOther.x + y * vOther.y + z * vOther.z);
    }
    float Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }
    float LengthSqr(void) const
    {
        return (x * x + y * y + z * z);
    }
    float Length2D() const
    {
        return sqrt(x * x + y * y);
    }

    Vec3& operator=(const Vec3& vOther)
    {
        x = vOther.x; y = vOther.y; z = vOther.z;
        return *this;
    }

    Vec3 operator-(void) const
    {
        return Vec3(-x, -y, -z);
    }
    Vec3 operator+(const Vec3& v) const
    {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }
    Vec3 operator-(const Vec3& v) const
    {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }
    Vec3 operator*(float fl) const
    {
        return Vec3(x * fl, y * fl, z * fl);
    }
    Vec3 operator*(const Vec3& v) const
    {
        return Vec3(x * v.x, y * v.y, z * v.z);
    }
    Vec3 operator/(float fl) const
    {
        return Vec3(x / fl, y / fl, z / fl);
    }
    Vec3 operator/(const Vec3& v) const
    {
        return Vec3(x / v.x, y / v.y, z / v.z);
    }

    float x, y, z;
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
		DEFINE_MEMBER_N(int8_t, PlayerStatus, 0xc); // 0 = Normal, 2 = Crouch, 1 = Prone, 80 = Aimdown
		DEFINE_MEMBER_N(bool, IsRunning, 0xD); // 40 = Jump, 80 = Sprint
		DEFINE_MEMBER_N(Vec3, PlayerPos, 0x24);
		DEFINE_MEMBER_N(Vec3, Acceleration, 0x30);
		DEFINE_MEMBER_N(int, WeaponSpeed, 0x3c);
		DEFINE_MEMBER_N(int, TimeToShoot, 0x40);
		DEFINE_MEMBER_N(int, CurrentWeapon, 0x144);
		DEFINE_MEMBER_N(int, WeaponState, 0x158); // 6 = Shoot, 11 = Reload
		DEFINE_MEMBER_N(float, TimeToAimDown, 0x168);
		DEFINE_MEMBER_N(Vec3, ViewAngle, 0x180);
		DEFINE_MEMBER_N(int, HeadDistance, 0x18c);
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

struct Enemy1
{
public:
	uintptr_t Point1 = 0x36d2248;
	uintptr_t Point2 = 0x36d2264;
	uintptr_t Point3 = 0x36d2278;
	uintptr_t Point4 = 0x36d2284;
};

extern Enemy1 Enm1;

#endif //INTTEMPLATE_OFFSETS_H
