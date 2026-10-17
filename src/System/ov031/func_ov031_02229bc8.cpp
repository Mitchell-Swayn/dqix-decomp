#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void OS_SpinWait(register unsigned int cycles);
extern "C" void DrainPendingCommandsResetDMAAndHalt(void);
// Original: arm9/ov031 @ 0x02229BC8; symbol: func_ov031_02229bc8; size: 0x34.
extern "C" void func_ov031_02229bc8(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    OS_SpinWait(0x01000000);
    DrainPendingCommandsResetDMAAndHalt();
}
