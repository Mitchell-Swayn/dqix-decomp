#include <globaldefs.h>
ARM
extern "C" int func_ov031_02207434(int);
extern "C" void _Z19SleepCurrentContextj(unsigned);
// Original: arm9/ov031 @ 0x022413C8; symbol: func_ov031_022413c8; size: 0x3C.
extern "C" void Overlay_WaitForStatusToLeaveMinusTwentySix(void *unused, int status) {
    int current = func_ov031_02207434(status);
    if (current == -26) {
        do {
            _Z19SleepCurrentContextj(0x1f4);
            current = func_ov031_02207434(status);
        } while (current == -26);
    }
}
