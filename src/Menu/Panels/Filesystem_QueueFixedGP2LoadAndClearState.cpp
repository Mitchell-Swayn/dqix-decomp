#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void *, const char *, const char *, void *);
extern "C" void *ResourceGroupTable_ResetView(void *);
// Original data: arm9/main @ 0x20f2a1c; symbol: data_020f2a1c.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 4b2b0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char *FilesystemQueueBackgroundPair_UnknownRoleDataReferences;
// Original data: arm9/main @ 0x20f2a28; symbol: data_020f2a28.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 442a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char *FilesystemQueueFixedGP2LoadAndClearState_UnknownRoleDataReferences;
// Original: arm9/ov023 @ 0x021E0B54; symbol: func_ov023_021e0b54; size: 0x48.
extern "C" int Filesystem_QueueFixedGP2LoadAndClearState(void *state) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    ResourceGroupTable_ResetView((unsigned char *)state + 0x7C);
    int task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, FilesystemQueueBackgroundPair_UnknownRoleDataReferences, FilesystemQueueFixedGP2LoadAndClearState_UnknownRoleDataReferences, 0);
    *(int *)((unsigned char *)state + 0x74C) = task;
    return 0x0E;
}
