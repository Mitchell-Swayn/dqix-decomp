#include <globaldefs.h>

#include <System/Interrupts.h>
extern "C" void WaitByLoop(unsigned);

// Original: arm9/main @ 0x020C9820; symbol: func_020c9820; size: 0x1C.
extern "C" ARM void System_WaitForInterruptOneAfterShortDelay() {
    WaitByLoop(1);
    WaitForInterrupt(true, 1);
}
