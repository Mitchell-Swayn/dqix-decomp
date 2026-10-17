#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0223442c(void);
// Original: arm9/ov031 @ 0x02234408; symbol: func_ov031_02234408; size: 0x24.
extern "C" void System_InstallCallback0223442CIfScreenContextClear(void) {
    if (ReadSelectedContextByte9(0) == 0)
        SetMainLoopCallback(func_ov031_0223442c);
}
