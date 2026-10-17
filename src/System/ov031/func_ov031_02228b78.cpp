#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void OS_SpinWait(unsigned int cycles);
extern "C" void DrainPendingCommandsResetDMAAndHalt(void);
// Original: arm9/ov031 @ 0x02228B78; symbol: func_ov031_02228b78; size: 0x34.
extern "C" void func_ov031_02228b78(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    OS_SpinWait(0x01000000);
    DrainPendingCommandsResetDMAAndHalt();
}
