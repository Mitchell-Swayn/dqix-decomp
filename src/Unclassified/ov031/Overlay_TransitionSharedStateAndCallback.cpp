#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void System_ResolveGlobalGroupEntry(int mode);
extern "C" void func_ov031_022339a8(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void SetSharedByteAndScheduleCallback33720(void);
extern "C" unsigned char data_ov031_02290cc8[];
// Original: arm9/ov031 @ 0x022336AC; symbol: func_ov031_022336ac; size: 0x54.
extern "C" void Overlay_TransitionSharedStateAndCallback(void) {
    switch (ReadSharedSignedByteAtOffset22()) {
    case 0:
        System_ResolveGlobalGroupEntry(7);
        break;
    case 1:
        System_ResolveGlobalGroupEntry(6);
        func_ov031_022339a8();
        data_ov031_02290cc8[2] = 1;
        break;
    default:
        return;
    }
    SetMainLoopCallback(SetSharedByteAndScheduleCallback33720);
}
