#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" volatile unsigned char data_ov031_02290cb8;
extern "C" void func_ov031_02222ddc(void);
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_02231e8c(void);
// Original: arm9/ov031 @ 0x02231E18; symbol: func_ov031_02231e18; size: 0x74.
extern "C" void Overlay_ContinueModeThreeIfStateClear(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (data_ov031_02290cb8 == 0) func_ov031_02222ddc();
    if (data_ov031_02290cb8 == 0) func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x14, 8);
    SetMainLoopCallback((void*)func_ov031_02231e8c);
}
