#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_02233ce0(void);
// Original: arm9/ov031 @ 0x02233CBC; symbol: func_ov031_02233cbc; size: 0x24.
extern "C" void System_InstallAlternateCallbackIfScreenZeroContextByteIsClear(void) {
    if (ReadSelectedContextByte9(0) == 0)
        SetMainLoopCallback(func_ov031_02233ce0);
}
