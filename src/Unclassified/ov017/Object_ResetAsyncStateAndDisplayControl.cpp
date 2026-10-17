#include <globaldefs.h>
ARM
extern "C" unsigned int Object_ReadGlobalDisplayContextWord(void);
extern "C" void Object_IgnoreRequestToken(unsigned int, unsigned int);
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" unsigned int data_02114e20;
extern "C" void func_020a0c0c(void);
// Original: arm9/ov017 @ 0x021A79F0; symbol: func_ov017_021a79f0; size: 0x6C.
extern "C" void Object_ResetAsyncStateAndDisplayControl(void *owner) {
    unsigned int context = Object_ReadGlobalDisplayContextWord();
    Object_IgnoreRequestToken(context, 0x205);
    BackgroundLoader_CancelEightTasksAndResetState(context);
    void *allocator = (char *)owner + 0x25c;
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    if (allocation != 0) {
        _ZN13SafeAllocator7DestroyEv(allocator);
        Memory_FreeThroughAllocatorUnion(&data_02114e20, allocation);
    }
    func_020a0c0c();
    volatile unsigned int *display = (volatile unsigned int *)0x04000000;
    *display = (*display & ~0x1f00) | (*(unsigned int *)((char *)owner + 0x1c) << 8);
}
