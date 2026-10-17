#include <globaldefs.h>
extern "C" int _Z29IsIPCCommandHandlerRegisteredi7IPCSide(unsigned, int);
extern "C" void _Z24SetArm9IPCCommandHandleriPFvjjjE(unsigned, void (*)(unsigned, unsigned, unsigned));
extern "C" int func_ov031_0221b284(unsigned, unsigned, unsigned, unsigned);
extern "C" void WaitByLoop(unsigned);
extern "C" void System_SetGlobalControlByteAndReturnHalfword(unsigned, unsigned, unsigned);
// Original: arm9/ov031 @ 0x0221B848; symbol: func_ov031_0221b848; size: 0x6C.
extern "C" int OV031_RegisterIPCHandlerAndWait(void) {
    while (!_Z29IsIPCCommandHandlerRegisteredi7IPCSide(4, 1)) {}
    _Z24SetArm9IPCCommandHandleriPFvjjjE(4, System_SetGlobalControlByteAndReturnHalfword);
    do {
        if (func_ov031_0221b284(7, 0, 0, 0) == 1) break;
        WaitByLoop(0x40000);
    } while (1);
    return 1;
}
