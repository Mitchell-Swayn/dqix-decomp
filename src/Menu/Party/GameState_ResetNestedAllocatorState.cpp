#include <globaldefs.h>
ARM
extern "C" void Menu_InitializeCatalogue(void *object);
extern "C" void _ZN13SafeAllocator5ResetEv(void *allocator);
// Original: arm9/ov002 @ 0x0215B428; symbol: func_ov002_0215b428; size: 0x30.
extern "C" void GameState_ResetNestedAllocatorState(void *object) {
    Menu_InitializeCatalogue((char *)object + 0x804);
    _ZN13SafeAllocator5ResetEv((char *)object + 0x850);
    *(unsigned int *)((char *)object + 0x2534) = 0;
    *(unsigned int *)((char *)object + 0x2538) = 0;
}
