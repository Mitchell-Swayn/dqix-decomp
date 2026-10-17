#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int screen);
extern "C" int IsGlobalControlAbsentOrByte19Clear();
extern "C" void func_ov031_0223c7c4(int);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void ClearDisplayPlaneMask(unsigned engine, unsigned mask);
extern "C" void SetSharedWords10And14(unsigned, unsigned);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void func_ov031_0222905c();
// Original: arm9/ov031 @ 0x02228FEC; symbol: func_ov031_02228fec; size: 0x70.
extern "C" void System_InitializeDisplaySequence(void) {
    if (ReadSelectedContextByte9(1)) return;
    if (ReadSelectedContextByte9(0)) return;
    if (!IsGlobalControlAbsentOrByte19Clear()) return;
    func_ov031_0223c7c4(0);
    Overlay_ProcessPendingFlag();
    ClearDisplayPlaneMask(1, 1);
    ClearDisplayPlaneMask(0, 0x15);
    SetSharedWords10And14(0, 1);
    SetMainLoopCallback(func_ov031_0222905c);
}
