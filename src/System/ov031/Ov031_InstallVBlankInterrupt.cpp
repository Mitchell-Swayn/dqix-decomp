#include <globaldefs.h>
extern "C" unsigned _Z19GetInterruptHandlerj(unsigned);
extern "C" void _Z28SetSpecificInterruptsEnabledj(unsigned);
extern "C" void _Z24EnableSpecificInterruptsj(unsigned);
extern "C" void _Z19SetInterruptHandlerjPKv(unsigned, const void*);
extern "C" void _Z29AcknowledgeSpecificInterruptsj(unsigned);
extern "C" void _Z19EnableIRQInterruptsv();
extern "C" unsigned char data_ov031_02290d58[];
extern "C" void func_ov031_0223d830();
// Original: arm9/ov031 @ 0x0223D780; symbol: func_ov031_0223d780; size: 0x74.
extern "C" ARM void Ov031_InstallVBlankInterrupt() {
    *(unsigned int*)(data_ov031_02290d58 + 4) = *(volatile unsigned int*)0x04000210;
    _Z28SetSpecificInterruptsEnabledj(0x40018);
    _Z24EnableSpecificInterruptsj(1);
    *(unsigned int*)data_ov031_02290d58 = _Z19GetInterruptHandlerj(1);
    _Z19SetInterruptHandlerjPKv(1, (const void*)func_ov031_0223d830);
    _Z29AcknowledgeSpecificInterruptsj(1);
    (void)*(volatile unsigned short*)0x04000208;
    *(volatile unsigned short*)0x04000208 = 1;
    _Z19EnableIRQInterruptsv();
}
