#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" int IsGlobalControlAbsentOrByte19Clear();
extern "C" void func_ov031_0223c7c4(int);
extern "C" int Overlay_ProcessPendingFlag();
extern "C" void ClearDisplayPlaneMask(unsigned engine,unsigned mask);
extern "C" void ReadOptionalSharedWords18And1C(unsigned* a,unsigned* b);
extern "C" void SetSharedWords10And14(unsigned a,unsigned b);
extern "C" void SetMainLoopWordPair(unsigned int a,unsigned int b);
extern "C" void func_ov031_02230ef0(unsigned char value);
extern "C" void SetMainLoopCallback(void(*)(void));
extern "C" void Ov031_InitializeSecondaryTransition();
extern "C" void func_ov031_0222ea24();
// Original: arm9/ov031 @ 0x0222E960; symbol: func_ov031_0222e960; size: 0xB4.
extern "C" void Graphics_TransitionFromIdleDisplayContexts() {
    if (ReadSelectedContextByte9(1)) return;
    if (ReadSelectedContextByte9(0)) return;
    if (!IsGlobalControlAbsentOrByte19Clear()) return;
    func_ov031_0223c7c4(0);
    Overlay_ProcessPendingFlag();
    ClearDisplayPlaneMask(1, 1);
    ClearDisplayPlaneMask(0, 0x15);
    unsigned value;
    ReadOptionalSharedWords18And1C(0, &value);
    if (value) {
        SetSharedWords10And14(2, 1);
        SetMainLoopCallback(Ov031_InitializeSecondaryTransition);
    } else {
        SetSharedWords10And14(2, 0);
        SetMainLoopWordPair(0, 0);
        func_ov031_02230ef0(0);
        SetMainLoopCallback(func_ov031_0222ea24);
    }
}
