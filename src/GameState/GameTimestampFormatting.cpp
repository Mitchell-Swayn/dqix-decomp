#include "GameState/GameState.h"
#include "System/Timing.h"

// Original: arm9/main @ 0x020103F0; symbol: func_020103f0; size: 0xDC.
extern "C" void GameState_ReadElapsedTimeComponents(GameState* state, unsigned short* hours,
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

// Original: arm9/main @ 0x020104CC; symbol: func_020104cc; size: 0xDC.
extern "C" void GameState_ComputeElapsedHoursMinutesSeconds(GameState* state, unsigned short* hours,
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

// Original: arm9/main @ 0x020105A8; symbol: func_020105a8; size: 0x5C.
extern "C" void GameState_ComputeElapsedMainTimestamp(GameState* state, unsigned int* elapsed)
{
    uint64_t current = (GetCurrentTimestamp() << 6) / 0x1ff6210;
    uint64_t stored = (state->mainTimestamp_ << 6) / 0x1ff6210;
    uint64_t delta = current - stored;
    *elapsed = delta;
}
