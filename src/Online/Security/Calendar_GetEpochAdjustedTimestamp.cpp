#include <globaldefs.h>
ARM
extern "C" unsigned RTC_GetDate(unsigned, unsigned, unsigned, unsigned);
extern "C" int RTC_GetTime(int);
extern "C" long long Calendar_ConvertDateTimeToSeconds(void*, int*);
// Original: arm9/ov031 @ 0x02207C98; symbol: func_ov031_02207c98; size: 0x38.
extern "C" unsigned Calendar_GetEpochAdjustedTimestamp(unsigned a, unsigned b, unsigned c, unsigned d) {
    int date[4];
    int time[3];
    RTC_GetDate((unsigned)date, b, c, d);
    RTC_GetTime((int)time);
    return (unsigned)Calendar_ConvertDateTimeToSeconds(date, time) + 0x386D4380;
}
