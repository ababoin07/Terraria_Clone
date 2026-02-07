#pragma once

#include <cstdint>

namespace Prng
{
struct Generator{
    uint64_t seed;
    const uint64_t a = 6364136223846793005ULL;
    const uint64_t c = 1ULL;
    const uint64_t m = 0;
    inline uint64_t next() {
        seed = (a * seed + c);
        return seed;
    }
    inline int range(const int& min, const int& max) {
        return min + (next() % (max - min + 1));
    }
};
}

using PrngGenerator = Prng::Generator;
