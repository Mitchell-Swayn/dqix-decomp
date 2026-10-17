#include <globaldefs.h>
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_02222ddc();
extern "C" unsigned char data_ov031_02290cc8[];
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void Network_TransitionMainLoopFromSelectedMode();
// Original: arm9/ov031 @ 0x02233720; symbol: func_ov031_02233720; size: 0x64.
extern "C" void System_ConfigureSecondaryDisplayMode() {
    if (ReadSelectedContextByte9(1)) return;
    if (data_ov031_02290cc8[2] != 0) func_ov031_02222ddc();
    func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x14, 8);
    SetMainLoopCallback(Network_TransitionMainLoopFromSelectedMode);
}
