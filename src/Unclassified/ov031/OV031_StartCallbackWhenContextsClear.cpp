#include <globaldefs.h>
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_02223568(int);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void func_ov031_0222b04c();
// Original: arm9/ov031 @ 0x0222B010; symbol: func_ov031_0222b010; size: 0x3C.
extern "C" void OV031_StartCallbackWhenContextsClear(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    func_ov031_02223568(1);
    SetMainLoopCallback(func_ov031_0222b04c);
}
