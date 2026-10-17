#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int screen);
extern "C" void func_ov031_02225bf0();
extern "C" int System_ResolveGlobalGroupEntry(int mode);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void func_ov031_0222de54();
// Original: arm9/ov031 @ 0x0222DE24; symbol: func_ov031_0222de24; size: 0x30.
extern "C" void System_InstallCallbackIfContextByteClear(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    func_ov031_02225bf0();
    System_ResolveGlobalGroupEntry(0x15);
    SetMainLoopCallback(func_ov031_0222de54);
}
