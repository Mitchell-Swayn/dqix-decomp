#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" unsigned int func_ov031_02227558(void);
extern "C" void SetSharedWords10And14(unsigned, unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_02228024(void);
extern "C" void Ov031_InitializeSecondaryTransition(void);
// Original: arm9/ov031 @ 0x02227FB0; symbol: func_ov031_02227fb0; size: 0x74.
extern "C" void Overlay_ConfigureTransitionCallbackFromState(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    unsigned state = func_ov031_02227558();
    switch (state) {
    case 0:
        SetSharedWords10And14(0, 1);
        SetMainLoopCallback((void*)func_ov031_02228024);
        break;
    case 1:
        SetSharedWords10And14(1, 1);
        SetMainLoopCallback((void*)Ov031_InitializeSecondaryTransition);
        break;
    default:
        break;
    }
}
