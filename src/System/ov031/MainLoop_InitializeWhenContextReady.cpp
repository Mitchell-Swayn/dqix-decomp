#include <globaldefs.h>
ARM

extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void func_ov031_0223c7c4(int);
extern "C" void Overlay_ProcessPendingFlag(void);
extern "C" void ClearDisplayPlaneMask(unsigned, unsigned);
extern "C" void SetSharedWords10And14(unsigned, unsigned);
extern "C" void SetMainLoopWordPair(unsigned, unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_022340c0(void);

// Original: arm9/ov031 @ 0x0222B5A0; symbol: func_ov031_0222b5a0; size: 0x70.
extern "C" void MainLoop_InitializeWhenContextReady(void) {
    if (ReadSelectedContextByte9(1) != 0) {
        return;
    }
    if (ReadSelectedContextByte9(0) != 0) {
        return;
    }
    func_ov031_0223c7c4(0);
    Overlay_ProcessPendingFlag();
    ClearDisplayPlaneMask(1, 1);
    ClearDisplayPlaneMask(0, 0x15);
    SetSharedWords10And14(0, 0);
    SetMainLoopWordPair(0, 1);
    SetMainLoopCallback(func_ov031_022340c0);
}
