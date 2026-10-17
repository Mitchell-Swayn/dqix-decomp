#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer();
extern "C" unsigned char data_ov031_02290c78[];
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void*);
extern "C" void System_SelectMainLoopFromContextState();
// Original: arm9/ov031 @ 0x0222A908; symbol: func_ov031_0222a908; size: 0x5C.
extern "C" void ConfigureThirdContextFromSharedState() {
    if (HasSharedObjectPointer()) return;
    if (data_ov031_02290c78[1] == 0) func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback((void*)System_SelectMainLoopFromContextState);
}
