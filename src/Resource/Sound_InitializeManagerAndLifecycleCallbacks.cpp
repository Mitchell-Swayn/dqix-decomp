#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/main @ 0x210cfc0; symbol: data_0210cfc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x210cfd0; symbol: data_0210cfd0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/main @ 0x210cfdc; symbol: data_0210cfdc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 9188 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void InitializeGlobalCommandMutexAndTablesOnce(void);
extern "C" void Sound_StopPlaybackAndWaitForCommands(void);
extern "C" void ResourceManager_InvokeGlobalReset(void);
extern "C" void PowerManagement_PrependSleepCallback(unsigned int);
extern "C" void LinkedList_AppendEntryToGlobalPendingList(unsigned int);
extern "C" void Sound_ResetChannelAndAlarmReservations(void);
extern "C" void NNSi_SndCaptureInit(void);
extern "C" void InitializeTwoAllocatorListsAndSixteenSlots(void);
// Original: arm9/main @ 0x020BBD14; symbol: func_020bbd14; size: 0x88.
extern "C" void Sound_InitializeManagerAndLifecycleCallbacks(void) {
    if (*(int *)(SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage + 0xc) != 0) return;
    *(int *)(SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage + 0xc) = 1;
    InitializeGlobalCommandMutexAndTablesOnce();
    *(unsigned int *)(SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage + 0x10) = (unsigned int)Sound_StopPlaybackAndWaitForCommands;
    *(int *)(SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage + 0x14) = 0;
    *(unsigned int *)(SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage + 0x1c) = (unsigned int)ResourceManager_InvokeGlobalReset;
    *(int *)(SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage + 0x20) = 0;
    PowerManagement_PrependSleepCallback((unsigned int)SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage_Variant2);
    LinkedList_AppendEntryToGlobalPendingList((unsigned int)SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage_Variant3);
    Sound_ResetChannelAndAlarmReservations();
    NNSi_SndCaptureInit();
    InitializeTwoAllocatorListsAndSixteenSlots();
    ((signed char *)SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage)[0] = -1;
    *(int *)(SoundInitializeManagerAndLifecycleCallbacks_UnknownRoleZeroInitializedStorage + 4) = 1;
}
