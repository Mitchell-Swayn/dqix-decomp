#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov001_02165828[];
extern "C" void Ov017_ClearFields3CThrough44(void *);
extern "C" unsigned char *_ZN13SafeAllocator8AllocateEj(void *, unsigned);
extern "C" void Resource_InitializeSb2ScriptBuffers(void *, void *, void *, int, void *, int);
extern "C" void InitializeIndexedPointerTable(void *);
// Original: arm9/ov001 @ 0x021538D4; symbol: func_ov001_021538d4; size: 0x74.
extern "C" void Memory_InitializeContextBuffersWhenEnabled(int enabled, int unused, void *allocator) {
    if (enabled == 0 || allocator == 0) {
        Ov017_ClearFields3CThrough44(data_ov001_02165828);
        return;
    }
    void *smallBuffer = _ZN13SafeAllocator8AllocateEj(allocator, 0x400);
    void *largeBuffer = _ZN13SafeAllocator8AllocateEj(allocator, 0x1800);
    Resource_InitializeSb2ScriptBuffers(data_ov001_02165828, (void *)enabled, smallBuffer, 0x80, largeBuffer, 0x200);
    InitializeIndexedPointerTable(data_ov001_02165828);
}
