#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void CancelOwnerTaskAndResetEmbeddedState(void*);
extern "C" void* _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*, const char*, const char*, void*);
// Original data: arm9/main @ 0x20f2a1c; symbol: data_020f2a1c.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 4b2b0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int FilesystemQueueBackgroundPair_UnknownRoleDataReferences;
// Original data: arm9/main @ 0x20f2a10; symbol: data_020f2a10.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 712a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int FilesystemQueueOwnerFilesInGP2_UnknownRoleDataReferences;
// Original: arm9/ov023 @ 0x021E0A48; symbol: func_ov023_021e0a48; size: 0x48.
extern "C" int Filesystem_QueueOwnerFilesInGP2(char* owner) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    CancelOwnerTaskAndResetEmbeddedState(owner + 0x8c);
    void* task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
        loader, *(const char**)&FilesystemQueueBackgroundPair_UnknownRoleDataReferences, *(const char**)&FilesystemQueueOwnerFilesInGP2_UnknownRoleDataReferences, 0);
    *(void**)(owner + 0x748) = task;
    return 0xc;
}
