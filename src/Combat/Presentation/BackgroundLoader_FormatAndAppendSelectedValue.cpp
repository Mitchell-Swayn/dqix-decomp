#include <globaldefs.h>
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void* Combat_GetCurrentPresentationAllocator(char*);
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
extern "C" int Combat_FormatScaledValue(int, char*);
extern "C" int BackgroundLoader_QueueResolvedPathWithSingleFence(char*);
extern "C" void Combat_TrackPresentationLoadTask(unsigned char*, int);
// Original: arm9/ov025 @ 0x021E4A08; symbol: func_ov025_021e4a08; size: 0x50.
extern "C" int BackgroundLoader_FormatAndAppendSelectedValue(void* object) {
    (void)_ZN16BackgroundLoader11GetInstanceEv();
    Combat_GetCurrentPresentationAllocator(*(char**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0x0c));
    char buffer[0x50];
    Combat_FormatScaledValue(*(int*)((char*)object + 8), buffer);
    int value = BackgroundLoader_QueueResolvedPathWithSingleFence(buffer);
    Combat_TrackPresentationLoadTask(*(unsigned char**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0x0c), value);
    return 1;
}
