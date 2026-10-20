#include <globaldefs.h>
void DisableIRQInterrupts(void); extern "C" void OS_Halt(void);
ARM
// Original: arm9/main @ 0x020C9BE0; symbol: func_020c9be0; size: 0x10.
extern "C" void DisableInterruptsAndHaltForever(void) { for (;;) { DisableIRQInterrupts(); OS_Halt(); } }
