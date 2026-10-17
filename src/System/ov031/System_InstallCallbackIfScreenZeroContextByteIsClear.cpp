#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0222b550(void);
// Original: arm9/ov031 @ 0x0222B52C; symbol: func_ov031_0222b52c; size: 0x24.
extern "C" void System_InstallCallbackIfScreenZeroContextByteIsClear(void) {
    if (ReadSelectedContextByte9(0) == 0)
        SetMainLoopCallback(func_ov031_0222b550);
}
