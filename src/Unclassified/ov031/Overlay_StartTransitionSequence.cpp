#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_02222ddc(void);
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void Graphics_TransitionFromIdleDisplayContexts(void);
// Original: arm9/ov031 @ 0x0222E910; symbol: func_ov031_0222e910; size: 0x50.
extern "C" void Overlay_StartTransitionSequence(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    func_ov031_02222ddc();
    func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback((void*)Graphics_TransitionFromIdleDisplayContexts);
}
