#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer();
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_0222d9a4(void);
extern "C" void* data_ov031_02290c98;
// Original: arm9/ov031 @ 0x0222E3A4; symbol: func_ov031_0222e3a4; size: 0x44.
extern "C" void Overlay_ClearSharedFlagAndSetCallback(void) {
    if (HasSharedObjectPointer()) return;
    void* object = data_ov031_02290c98;
    unsigned* word = *(unsigned**)((char*)object + 4);
    *word &= 0xc1fffcff;
    SetMainLoopCallback(func_ov031_0222d9a4);
}
