#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int screen);
extern "C" void func_ov031_02223568(unsigned mode);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_022286f4(void);
// Original: arm9/ov031 @ 0x022286B8; symbol: func_ov031_022286b8; size: 0x3C.
extern "C" void Overlay_SelectModeAndCallbackWhenContextsClear(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    func_ov031_02223568(3);
    SetMainLoopCallback(func_ov031_022286f4);
}
