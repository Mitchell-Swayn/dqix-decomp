#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" int func_ov031_02227840(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0222a274(void);
// Original: arm9/ov031 @ 0x0222A244; symbol: func_ov031_0222a244; size: 0x30.
extern "C" void Overlay_SetMainLoopCallbackWhenContextByteZero(void) {
    if (ReadSelectedContextByte9(0) != 0)
        return;
    if (func_ov031_02227840() == 0)
        return;
    SetMainLoopCallback(func_ov031_0222a274);
}
