#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_02223568(unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_0222a4bc(void);
// Original: arm9/ov031 @ 0x0222A480; symbol: func_ov031_0222a480; size: 0x3C.
extern "C" void Overlay_StartContextModeThree(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    func_ov031_02223568(3);
    SetMainLoopCallback((void*)func_ov031_0222a4bc);
}
