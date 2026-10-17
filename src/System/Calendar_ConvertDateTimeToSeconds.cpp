#include <globaldefs.h>
ARM
extern "C" int Calendar_ConvertValidatedDateToDayCount(void* date);
extern "C" int RealTimeClock_ConvertTimeToSeconds(int* time);
// Original: arm9/main @ 0x020CF990; symbol: func_020cf990; size: 0x64.
extern "C" long long Calendar_ConvertDateTimeToSeconds(void* date, int* time) {
    int days = Calendar_ConvertValidatedDateToDayCount(date);
    if (days == -1) return -1;
    int seconds = RealTimeClock_ConvertTimeToSeconds(time);
    long long timestamp;
    if (seconds == -1)
        timestamp = -1;
    else {
        timestamp = seconds;
        timestamp += (long long)days * 86400;
    }
    return timestamp;
}
