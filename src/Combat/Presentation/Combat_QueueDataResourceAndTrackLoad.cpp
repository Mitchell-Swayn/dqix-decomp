#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" void* CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[4];
extern "C" const char Combat_QueueDataResourceAndTrackLoad_PathDataS[];
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void* Combat_GetCurrentPresentationAllocator(char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" int BackgroundLoader_QueueResolvedPathWithSingleFence(const char*);
extern "C" void Combat_TrackPresentationLoadTask(unsigned char*, int);
// Original: arm9/ov025 @ 0x021E40E4; symbol: func_ov025_021e40e4; size: 0x58.
extern "C" int Combat_QueueDataResourceAndTrackLoad(void* object) {
    char buffer[0x50];
    _ZN16BackgroundLoader11GetInstanceEv();
    Combat_GetCurrentPresentationAllocator((char*)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3]);
    sprintf(buffer, Combat_QueueDataResourceAndTrackLoad_PathDataS, *(unsigned*)((char*)object + 8));
    int value = BackgroundLoader_QueueResolvedPathWithSingleFence(buffer);
    Combat_TrackPresentationLoadTask((unsigned char*)((char*)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3]), value);
    return 1;
}
