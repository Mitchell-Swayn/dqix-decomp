#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void Ov031_SetGlobalObjectField1E298(unsigned int value);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void Math_InitializeDivisionAndInverse(void);
extern "C" void func_ov031_02229964(void);
// Original: arm9/ov031 @ 0x02229860; symbol: func_ov031_02229860; size: 0x30.
extern "C" void Overlay_InitializeCallbacksWhenContextByteZero(void) {
    if (ReadSelectedContextByte9(0) != 0) return;
    Ov031_SetGlobalObjectField1E298((unsigned int)func_ov031_02229964);
    SetMainLoopCallback(Math_InitializeDivisionAndInverse);
}
