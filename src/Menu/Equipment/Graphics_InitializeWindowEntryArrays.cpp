#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator5ResetEv(void* self);
extern "C" char* _ZN13SafeAllocator8AllocateEj(void* self, unsigned size);
extern "C" void Window_AllocateAndInitializeEntryArraysAndControls(unsigned char* p, unsigned a, unsigned b, unsigned active, void* allocator, int count, unsigned char kind);
// Original: arm9/ov005 @ 0x02159C24; symbol: func_ov005_02159c24; size: 0x64.
extern "C" void Graphics_InitializeWindowEntryArrays(char* self, unsigned active, unsigned state) {
    _ZN13SafeAllocator5ResetEv(self + 0x280);
    *(char**)(self + 0xe64) = _ZN13SafeAllocator8AllocateEj(self + 0x280, 0x24);
    Window_AllocateAndInitializeEntryArraysAndControls((unsigned char*)*(char**)(self + 0xe64), 0, 1, active, self + 0x280, 4, 0x40);
    *(unsigned*)(self + 0xe68) = state;
}
