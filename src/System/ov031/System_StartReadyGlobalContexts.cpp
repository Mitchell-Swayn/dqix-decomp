#include <globaldefs.h>
ARM
extern "C" void System_SwitchGlobalProcessorContext();
extern "C" void System_MarkGlobalContextReadyAndSwitch();
extern "C" int Ov031_IsGlobalModeTwoOrThree();
extern "C" void func_ov031_02211864(int,int);
extern "C" int *data_ov031_0224e590;
// Original: arm9/ov031 @ 0x022111E0; symbol: func_ov031_022111e0; size: 0x8C.
extern "C" int System_StartReadyGlobalContexts() {
    if (!data_ov031_0224e590) {
        func_ov031_02211864(9, -2);
        return 0;
    }
    if (Ov031_IsGlobalModeTwoOrThree()) return 0;
    if (!data_ov031_0224e590[1] && !data_ov031_0224e590[15]) {
        func_ov031_02211864(9, -2);
        return 0;
    }
    System_SwitchGlobalProcessorContext();
    System_MarkGlobalContextReadyAndSwitch();
    data_ov031_0224e590[0] = 2;
    return 1;
}
