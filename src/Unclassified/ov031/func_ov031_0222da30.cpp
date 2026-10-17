#include <globaldefs.h>
ARM
extern "C" unsigned int GetByteAtOffset60FromGlobalPointer(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0222da50(void);
// Original: arm9/ov031 @ 0x0222DA30; symbol: func_ov031_0222da30; size: 0x20.
extern "C" void func_ov031_0222da30(void) {
    if (GetByteAtOffset60FromGlobalPointer() != 0x1f) SetMainLoopCallback(func_ov031_0222da50);
}
