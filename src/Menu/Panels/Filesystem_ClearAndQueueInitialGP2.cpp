#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void *ResourceGroupTable_ResetView(void *);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void *, const char *, const char *, void *);
// Original data: arm9/main @ 0x20f2a1c; symbol: data_020f2a1c.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 4b2b0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const char *FilesystemQueueBackgroundPair_UnknownRoleDataReferences;
// Original data: arm9/main @ 0x20f2b68; symbol: data_020f2b68.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 522a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const char *FilesystemClearAndQueueInitialGP2_UnknownRoleDataReferences;
// Original: arm9/ov023 @ 0x021E07F8; symbol: func_ov023_021e07f8; size: 0x48.
extern "C" int Filesystem_ClearAndQueueInitialGP2(void *self) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    ResourceGroupTable_ResetView((char *)self + 0x6C);
    int handle = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, FilesystemQueueBackgroundPair_UnknownRoleDataReferences, FilesystemClearAndQueueInitialGP2_UnknownRoleDataReferences, 0);
    *(int *)((char *)self + 0x744) = handle;
    return 10;
}
