#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" volatile unsigned char data_02109da4[];
extern "C" volatile signed char data_02109dae[];
extern "C" signed char data_020f1962[];
extern "C" void func_020a1940(int);
// Original: arm9/main @ 0x020A1E54; symbol: func_020a1e54; size: 0x5C.
extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int enabled) {
    if (data_02109da4[0] == 0) return;
    data_02109da4[0] = data_02109da4[0] - 1;
    if (enabled != 0) {
        int count = data_02109da4[0];
        if (count != 0) {
            int index = (int)(signed char)data_02109dae[data_02109da4[0] - 1];
            func_020a1940((int)data_020f1962[index]);
        }
    }
}
