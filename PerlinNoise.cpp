#include <cmath>
#include "PerlinNoise.h"

PerlinType PerlinNoise::Generator::DotProduct(PerlinType X0, PerlinType Y0, PerlinType X1, PerlinType Y1)
{
    return X0 * Y0 + X1 * Y1;
}
PerlinType PerlinNoise::Generator::Lerp(PerlinType D0, PerlinType D1, PerlinType T)
{
    return (D1 - D0) * T + D0;
}
PerlinType PerlinNoise::Generator::Hash1D(int64_t Data)
{
    uint64_t Hash = static_cast<uint64_t>(Data) ^ Seed;

    Hash = (Hash ^ (Hash >> 30)) * 0xbf58476d1ce4e5b9ULL;
    Hash = (Hash ^ (Hash >> 27)) * 0x94d049bb133111ebULL;
    Hash = Hash ^ (Hash >> 31);

    return static_cast<PerlinType>(Hash >> 11) / 9007199254740992.0;
}
PerlinType PerlinNoise::Generator::Hash2D(int64_t Data0, int64_t Data1)
{
    uint64_t Hash0 = static_cast<uint64_t>(Data0) ^ Seed;

    Hash0 = (Hash0 ^ (Hash0 >> 30)) * 0xbf58476d1ce4e5b9ULL;
    Hash0 = (Hash0 ^ (Hash0 >> 27)) * 0x94d049bb133111ebULL;
    Hash0 = Hash0 ^ (Hash0 >> 31);

    uint64_t Hash1 = static_cast<uint64_t>(Data1) ^ Seed;

    Hash1 = (Hash1 ^ (Hash1 >> 27)) * 0xa4e56f2a104b5e6cULL;
    Hash1 = (Hash1 ^ (Hash1 >> 24)) * 0x894a48b56c56efd5ULL;
    Hash1 = Hash1 ^ (Hash1 >> 33);

    Hash0 ^= Hash1;

    return static_cast<PerlinType>(Hash0 >> 11) / 9007199254740992.0;
}
PerlinType PerlinNoise::Generator::Perlin1D(PerlinType X)
{
    double Left = Hash1D(std::floor(X));
    double Right = Hash1D(std::floor(X) + 1);

    PerlinType T = Smooth(X - std::floor (X));

    return (Lerp(Left, Right, T)) * 2 - 1;
}
PerlinType PerlinNoise::Generator::Perlin2D(PerlinType X, PerlinType Y)
{
    int64_t FX = std::floor(X);
    int64_t FY = std::floor(Y);

    PerlinType XMod1 = X - FX;
    PerlinType YMod1 = Y - FY;

    PerlinType Angle00 = Hash2D(FX, FY) * Pi2;
    PerlinType Angle10 = Hash2D(FX + 1, FY) * Pi2;
    PerlinType Angle01 = Hash2D(FX, FY + 1) * Pi2;
    PerlinType Angle11 = Hash2D(FX + 1, FY + 1) * Pi2;

    PerlinType Dot00 = DotProduct(std::cos(Angle00), std::sin(Angle00), XMod1, YMod1);
    PerlinType Dot10 = DotProduct(std::cos(Angle10), std::sin(Angle10), XMod1 - 1, YMod1);
    PerlinType Dot01 = DotProduct(std::cos(Angle01), std::sin(Angle01), XMod1, YMod1 - 1);
    PerlinType Dot11 = DotProduct(std::cos(Angle11), std::sin(Angle11), XMod1 - 1, YMod1 - 1);

    PerlinType SmoothedX = Smooth(XMod1);

    return Lerp(Lerp(Dot00, Dot10, SmoothedX), Lerp(Dot01, Dot11, SmoothedX), Smooth(YMod1));
}

