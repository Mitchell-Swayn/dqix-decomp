#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage;
extern "C" void SoundSfx_RestoreHeapAfterGroupPlayback(unsigned char *);
extern "C" void SoundSfx_LoadGroupAtCurrentHeapState(void *, unsigned int, unsigned short);
extern "C" void ResourceHandle_InvokeOperationWithValidHalfwordIndex(char *, int, int);
extern "C" unsigned long long _Z19GetCurrentTimestampv(void);
extern "C" void *PartyProgress_GetInstance(void);
extern "C" void PartyProgress_CaptureRecoveryZoneOnce(char *);
// Original: arm9/ov017 @ 0x021C2E50; symbol: func_ov017_021c2e50; size: 0x54.
extern "C" void Resource_StartHandleAndCaptureTimestamp(unsigned char *state) {
    SoundSfx_RestoreHeapAfterGroupPlayback(&Main_UnknownRoleZeroInitializedStorage);
    SoundSfx_LoadGroupAtCurrentHeapState(&Main_UnknownRoleZeroInitializedStorage, 0xB3, 0xB3);
    ResourceHandle_InvokeOperationWithValidHalfwordIndex((char *)&Main_UnknownRoleZeroInitializedStorage, 0, 0);
    unsigned long long timestamp = _Z19GetCurrentTimestampv();
    *(unsigned int *)(state + 0x98) = (unsigned int)timestamp;
    *(unsigned int *)(state + 0x9C) = (unsigned int)(timestamp >> 32);
    PartyProgress_CaptureRecoveryZoneOnce((char *)PartyProgress_GetInstance());
    state[0x8C] = 3;
}
