#pragma optimize_for_size off
#include <globaldefs.h>
#pragma opt_common_subs off
// Original: arm9/main @ 0x020CFAF4; symbol: func_020cfaf4; size: 0x80.
extern "C" void Calendar_ConvertClampedSecondsToHoursMinutesSeconds(int* output, int seconds) {
    if (seconds < 0) seconds = 0;
    if (seconds > 86399) seconds = 86399;
    int minutes = seconds / 60;
    output[2] = seconds % 60;
    output[1] = minutes % 60;
    output[0] = minutes / 60;
}
