#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*, const char*, const char*, void*);
extern "C" void CancelOwnerTaskAndResetEmbeddedState(void*);
// Original data: arm9/main @ 0x20f2a1c; symbol: data_020f2a1c.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 4b2b0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char* FilesystemQueueBackgroundPair_UnknownRoleDataReferences;
// Original data: arm9/main @ 0x20f2a20; symbol: data_020f2a20.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 812a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char* FilesystemQueueBackgroundPair_UnknownRoleDataReferences_Variant2;
// Original: arm9/ov023 @ 0x021E0C38; symbol: func_ov023_021e0c38; size: 0x48.
extern "C" int Filesystem_QueueBackgroundPair(void* self) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    CancelOwnerTaskAndResetEmbeddedState((char*)self + 0xA4);
    *(unsigned*)((char*)self + 0x750) = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, FilesystemQueueBackgroundPair_UnknownRoleDataReferences, FilesystemQueueBackgroundPair_UnknownRoleDataReferences_Variant2, 0);
    return 3;
}
