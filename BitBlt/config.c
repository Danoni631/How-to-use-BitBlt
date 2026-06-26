#include "include.h"
#include "config.h"

static DWORD xs;

void SeedXorshift32(DWORD dwSeed) {
    xs = dwSeed;
}

DWORD xorshift32() {
    xs ^= xs << 13;
    xs ^= xs << 17;
    xs ^= xs << 5;
    return xs;
}

static DWORD GetSeed() {
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    return (DWORD)(counter.QuadPart & 0xFFFFFFFF);
}
