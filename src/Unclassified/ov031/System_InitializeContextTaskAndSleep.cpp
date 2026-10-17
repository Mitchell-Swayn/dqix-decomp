#include <globaldefs.h>
ARM
extern "C" void *Memory_AllocateZeroedBlock(unsigned int, int);
extern "C" void * volatile data_ov031_02290c48;
extern "C" void func_ov031_02227cd8(void);
extern "C" void func_ov031_02227cb0(void);
extern "C" void func_ov031_02227cc8(void);
extern "C" int func_ov031_02222928(unsigned int, unsigned int, void (*)(void), void (*)(void), void (*)(void), unsigned int);
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void _Z19SleepCurrentContextj(unsigned int);
// Original: arm9/ov031 @ 0x02227B38; symbol: func_ov031_02227b38; size: 0x6C.
extern "C" void System_InitializeContextTaskAndSleep(void) {
    data_ov031_02290c48 = Memory_AllocateZeroedBlock(0xc, -4);
    int result = func_ov031_02222928(0xf, 0x40, func_ov031_02227cb0, func_ov031_02227cc8, func_ov031_02227cd8, 0x800);
    if (result != 1) DisableInterruptsAndHaltForever();
    _Z19SleepCurrentContextj(10);
}
