#include <globaldefs.h>
extern "C" unsigned data_ov031_022919bc[];
extern "C" unsigned char data_ov031_022919c4[];
extern "C" void Overlay_WaitForStatusToLeaveMinusTwentySix(void*, int);
extern "C" void Util_InvokeObjectCallbacks(void*);
// Original: arm9/ov031 @ 0x022417FC; symbol: func_ov031_022417fc; size: 0x60.
extern "C" void Overlay_ProcessPendingStatusCallbacks(void) {
    if (data_ov031_022919bc[0] == data_ov031_022919bc[1]) return;
    do {
        Overlay_WaitForStatusToLeaveMinusTwentySix(0, *(unsigned*)(data_ov031_022919c4 + data_ov031_022919bc[1] * 8));
        Util_InvokeObjectCallbacks(*(void**)(data_ov031_022919c4 + data_ov031_022919bc[1] * 8 + 4));
        data_ov031_022919bc[1] = (data_ov031_022919bc[1] + 1) & 7;
    } while (data_ov031_022919bc[0] != data_ov031_022919bc[1]);
}
