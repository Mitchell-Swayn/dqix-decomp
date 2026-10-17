#include <globaldefs.h>
ARM
extern "C" void func_ov004_02169144(void);
extern "C" void ComputeGrottoAndContextDependentStateFlags(int);
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void *);
// Original: arm9/ov004 @ 0x0216AA10; symbol: func_ov004_0216aa10; size: 0x60.
extern "C" int Grotto_ConfigureHardwareAndRefreshContext(void) {
    func_ov004_02169144();
    volatile unsigned short *registers = (volatile unsigned short *)0x04001008;
    registers[0] = (registers[0] & ~3) | 1;
    registers[1] = (registers[1] & ~3) | 2;
    registers[2] &= ~3;
    ComputeGrottoAndContextDependentStateFlags(0);
    void *context = (void *)ReadWordFieldAtOffset1C();
    if (*(unsigned int *)((char *)context + 0x998) != 0) ResetGlobalOwnerAndEmbeddedSelectionState(context);
    return 0;
}
