#include <globaldefs.h>
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_0223c7c4(unsigned);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void ClearDisplayPlaneMask(unsigned, unsigned);
extern "C" void SetSharedWords10And14(unsigned, unsigned);
extern "C" void SetMainLoopWordPair(unsigned, unsigned);
extern "C" void func_ov031_022340c0();
extern "C" void SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x0223447C; symbol: func_ov031_0223447c; size: 0x70.
extern "C" ARM void Ov031_ConfigureDisplayAfterContextReady() {
    if (ReadSelectedContextByte9(1)) return;
    if (ReadSelectedContextByte9(0)) return;
    func_ov031_0223c7c4(0);
    Overlay_ProcessPendingFlag();
    ClearDisplayPlaneMask(1, 1);
    ClearDisplayPlaneMask(0, 0x15);
    SetSharedWords10And14(0, 0);
    SetMainLoopWordPair(0, 2);
    SetMainLoopCallback(func_ov031_022340c0);
}
