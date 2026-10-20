#include <globaldefs.h>
ARM
extern "C" bool Bgm_IsTemporarySequencePendingOrPlaying(char *);
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(void *);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void *, int);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov003 @ 0x0215C510; symbol: Filesystem_CancelLoadAndResetTaskStateWhenUnneeded; size: 0x58.
// When the override test and byte +0x59D are clear, frees loader allocations, removes task +0x578, resets it to -1, and sets bytes +0x588 and +0x580 to 0xB and zero.
extern "C" void Filesystem_CancelLoadAndResetTaskStateWhenUnneeded(char *p) {
    if (Bgm_IsTemporarySequencePendingOrPlaying((char *)Main_UnknownRoleZeroInitializedStorage_Variant2) || (unsigned char)p[0x59d] != 0) return;
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    _ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(loader);
    _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int *)(p + 0x578));
    *(int *)(p + 0x578) = -1;
    p[0x588] = 0xb;
    p[0x580] = 0;
}
