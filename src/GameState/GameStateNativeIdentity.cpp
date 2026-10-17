#include "GameState/GameState.h"
#include "System/Timing.h"
#include "Util/Random.h"

#if defined(usa)

typedef char NativeIdentitySizeCheck[sizeof(NativeIdentity) == 6 ? 1 : -1];
typedef char GameStateIdentityRecordSizeCheck[
    sizeof(GameStateIdentityRecord) == 12 ? 1 : -1];
typedef char GameStateNativeIdentityOffsetCheck[
    offsetof(GameState, nativeIdentity_) == 0x74fe ? 1 : -1];
typedef char GameStateIdentityRecordsOffsetCheck[
    offsetof(GameState, identityRecords_) == 0x7f8c ? 1 : -1];
typedef char GameStateNativeIdentityStateSizeCheck[
    sizeof(GameState) == 0x7ff4 ? 1 : -1];

extern "C" int StoreOperationResultAndFinalizeSuccess(unsigned int* values);
extern "C" void System_ReadHardwareMacAddress(unsigned char* bytes);

extern "C" char data_020ef0ca[]; // "CreateNativeID"; string-pool ownership pending

// Original: arm9/main @ 0x020120F0; symbol: func_020120f0; size: 0x110.
extern "C" void GameState_GenerateNativeIdentityFromClockAndHardware(GameState* state)
{
    Random random;
    unsigned int clock[3];
    uint64_t seeds[6];
    unsigned char hardware[6];
    CreateRandom(&random, data_020ef0ca, 0);
    // The release ignores the clock read's status before using its output.
    StoreOperationResultAndFinalizeSuccess(clock);
    System_ReadHardwareMacAddress(hardware);
    seeds[0] = clock[0];
    seeds[1] = clock[1];
    seeds[2] = clock[2];
    seeds[3] = ((unsigned int)GetCurrentTimestamp() << 6) / 0x82ea;
    seeds[4] = ((unsigned int)GetCurrentTimestamp() * 0xfa00) / 0x82ea;
    unsigned int packed = ((unsigned int)hardware[5] << 24) |
                          (hardware[4] << 16) | (hardware[3] << 8) | hardware[2];
    seeds[5] = (int)packed;
    for (int i = 0; i < 6; ++i) {
        SeedRandom(&random, seeds[i]);
        state->nativeIdentity_.bytes_[i] = NextRandom(&random);
    }
}

#endif
