#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void func_ov031_02223568(int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_02234a68(void);
// Original: arm9/ov031 @ 0x02234A3C; symbol: func_ov031_02234a3c; size: 0x2C.
extern "C" void System_InstallAlternateCallbackWhenSelectedContextByte9Zero(void) {
    if (ReadSelectedContextByte9(0) != 0)
        return;
    func_ov031_02223568(2);
    SetMainLoopCallback(func_ov031_02234a68);
}
