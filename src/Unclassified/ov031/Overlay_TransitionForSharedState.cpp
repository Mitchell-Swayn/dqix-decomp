#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void System_ResolveGlobalGroupEntry(int mode);
extern "C" void func_ov031_0222855c(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ConfigureDisplayPlanesAndCallback(void);
extern "C" void func_ov031_022283d8(void);
// Original: arm9/ov031 @ 0x02228388; symbol: func_ov031_02228388; size: 0x50.
extern "C" void Overlay_TransitionForSharedState(void) {
    int state = ReadSharedSignedByteAtOffset22();
    switch (state) {
    case 0:
        System_ResolveGlobalGroupEntry(7);
        SetMainLoopCallback(System_ConfigureDisplayPlanesAndCallback);
        break;
    case 1:
        System_ResolveGlobalGroupEntry(6);
        func_ov031_0222855c();
        SetMainLoopCallback(func_ov031_022283d8);
        break;
    }
}
