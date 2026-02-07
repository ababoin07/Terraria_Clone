#pragma once

#include <cstdint>
#include <cmath>

using PerlinType = double;

namespace PerlinNoise{

const PerlinType Pi = std::acos(-1);
const PerlinType Pi2 = 2 * Pi;

struct Generator{
    uint64_t Seed;
    PerlinType DotProduct(PerlinType, PerlinType, PerlinType, PerlinType);
    PerlinType Lerp(PerlinType, PerlinType, PerlinType);
    PerlinType Hash1D(int64_t);
    PerlinType Hash2D(int64_t, int64_t);
    PerlinType Smooth(PerlinType T)
    {
        return T * T * T * (T * (T * 6 - 15) + 10);
    }
    PerlinType Perlin1D(PerlinType);
    PerlinType Perlin2D(PerlinType, PerlinType);
};
}

using PerlinNoiseGenerator = PerlinNoise::Generator;
