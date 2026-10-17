// SDK support (community reconstruction): WaitByLoop.
// Original: arm9/main @ 0x02000466; symbol: WaitByLoop; size: 0x4.
#include <globaldefs.h>
// ARM9 main 0x02000466, original ABI symbol WaitByLoop.
// SDK community assembly: SVC_WaitByLoop, NitroSDK commit
// 9eec6c92c9d7bba9350732b11296ed16aab3a8bc,
// libraries/syscall/asm/subpsyscall.s. Necessary BIOS SWI veneer;
// preserved existing ABI name. Assembly coverage only, no C/C++ credit.
extern "C" THUMB asm void WaitByLoop(int count)
{
    swi 3
    bx lr
}
