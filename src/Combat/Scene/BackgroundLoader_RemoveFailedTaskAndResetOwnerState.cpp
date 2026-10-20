#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*, unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
// Original data: arm9/ov000 @ 0x2184220; symbol: data_ov000_02184220.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned BattleSceneUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov000 @ 0x02160DE4; symbol: func_ov000_02160de4; size: 0x64.
extern "C" void BackgroundLoader_RemoveFailedTaskAndResetOwnerState(void *p) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    if ((int)_ZN16BackgroundLoader13GetTaskStatusEi(loader, (unsigned)*(short *)((char *)p + 0x7730)) >= 0) return;
    _ZN16BackgroundLoader10RemoveTaskEi(loader, *(short *)((char *)p + 0x7730));
    *(short *)((char *)p + 0x7730) = -1;
    *(unsigned *)((char *)p + 0xea8) = 0x11;
    *(unsigned *)((char *)p + 0xeac) = 0;
    BattleSceneUpdate_UnknownRoleZeroInitializedStorage = 1;
}
