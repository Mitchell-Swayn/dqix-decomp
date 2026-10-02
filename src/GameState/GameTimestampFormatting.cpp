#include "GameState/GameState.h"
#include "System/Timing.h"

extern "C" void func_020103f0(GameState* state, unsigned short* hours,
                              unsigned char* minutes, unsigned char* seconds)
{
    uint64_t current = (GetCurrentTimestamp() << 6) / 0x1ff6210;
    uint64_t stored = (state->mainTimestamp_ << 6) / 0x1ff6210;
    uint64_t elapsed = current - stored;

    uint64_t hourCount = elapsed / 0xe10;
    uint64_t minuteCount = (elapsed / 0x3c) % 0x3c;
    uint64_t secondCount = elapsed % 0x3c;
    if (hourCount > 0x2710)
        hourCount = 0x270f;

    *hours = hourCount;
    *minutes = minuteCount;
    *seconds = secondCount;
}

extern "C" void func_020104cc(GameState* state, unsigned short* hours,
                              unsigned char* minutes, unsigned char* seconds)
{
    uint64_t current = (GetCurrentTimestamp() << 6) / 0x1ff6210;
    uint64_t stored = (state->altTimestamp_ << 6) / 0x1ff6210;
    uint64_t elapsed = current - stored;

    uint64_t hourCount = elapsed / 0xe10;
    uint64_t minuteCount = (elapsed / 0x3c) % 0x3c;
    uint64_t secondCount = elapsed % 0x3c;
    if (hourCount > 0x2710)
        hourCount = 0x270f;

    *hours = hourCount;
    *minutes = minuteCount;
    *seconds = secondCount;
}
