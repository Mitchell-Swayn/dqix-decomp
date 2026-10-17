#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void func_ov031_02223568(int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_02229f70(void);
// Original: arm9/ov031 @ 0x02229F44; symbol: func_ov031_02229f44; size: 0x2C.
extern "C" void System_InstallCallbackWhenSelectedContextByte9Zero(void) {
    if (ReadSelectedContextByte9(0) != 0)
        return;
    func_ov031_02223568(3);
    SetMainLoopCallback(func_ov031_02229f70);
}
