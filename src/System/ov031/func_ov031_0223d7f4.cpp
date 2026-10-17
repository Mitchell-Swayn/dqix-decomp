#include <globaldefs.h>
ARM
extern "C" void _Z28SetSpecificInterruptsEnabledj(unsigned int);
extern "C" void _Z19SetInterruptHandlerjPKv(unsigned int, const void*);
extern "C" unsigned int data_ov031_02290d58;
// Original: arm9/ov031 @ 0x0223D7F4; symbol: func_ov031_0223d7f4; size: 0x3C.
extern "C" void func_ov031_0223d7f4(void) {
    unsigned short previous = *(volatile unsigned short*)0x04000208;
    (void)previous;
    *(volatile unsigned short*)0x04000208 = 0;
    _Z28SetSpecificInterruptsEnabledj(*(unsigned int*)((char*)&data_ov031_02290d58 + 4));
    _Z19SetInterruptHandlerjPKv(1, (const void*)data_ov031_02290d58);
}
