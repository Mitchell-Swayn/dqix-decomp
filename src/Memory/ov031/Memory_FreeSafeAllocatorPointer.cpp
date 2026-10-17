#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02291e3c[];
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" void _ZN13SafeAllocator4FreeEPv(void *, void *);
extern "C" int _Z20SetIRQInterruptStatei(int);
// Original: arm9/ov031 @ 0x022434E8; symbol: func_ov031_022434e8; size: 0x30.
extern "C" void Memory_FreeSafeAllocatorPointer(void *unused, void *pointer) {
    if (pointer == 0)
        return;
    int irqState = _Z20DisableIRQInterruptsv();
    _ZN13SafeAllocator4FreeEPv(data_ov031_02291e3c, pointer);
    _Z20SetIRQInterruptStatei(irqState);
}
