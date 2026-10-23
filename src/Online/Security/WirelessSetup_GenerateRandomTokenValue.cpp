#include <globaldefs.h>
THUMB
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" void Memory_FillBufferWithLowByteUsingVectorizedMemset(void *, unsigned, unsigned);
extern "C" int RTC_GetTime(int);
// Original data: arm9/ov031 @ 0x0224E6E0; symbol: data_ov031_0224e6e0.
// Shared zero-initialized state; offsets 8 and 24..32 hold the RNG initialization flag and recurrence words.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
// Seeds the recurrence once from clock fields, advances it, and scales its high halfword to a token.
// Original: arm9/ov031 @ 0x0221E664; symbol: func_ov031_0221e664; size: 0x70.
extern "C" unsigned WirelessSetup_GenerateRandomTokenValue() {
    if (*(unsigned *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 8) == 0) {
        unsigned seed = 0;
        unsigned time[3];
        Memory_FillBufferWithLowByteUsingVectorizedMemset(time, 0, 12);
        if (RTC_GetTime((int)time) == 0) {
            seed += time[0] << 10;
            seed += time[1] << 3;
            seed += time[2];
        }
        *(unsigned *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 24) = seed;
        *(unsigned *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 28) = 0x5d588b65;
        *(unsigned *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 32) = 0x269ec3;
        *(unsigned *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 8) = 1;
    }
    unsigned next = *(unsigned *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 28) * *(unsigned *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 24) + *(unsigned *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 32);
    *(unsigned *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 24) = next;
    return (unsigned short)(((next >> 16) * 0x7fff) >> 16);
}
