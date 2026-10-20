#include <globaldefs.h>
struct TimeRecord
{
    unsigned short hours;
    unsigned char minutes, seconds;
};
extern "C" void TimeRecord_AddMinutesWithHourCarry(TimeRecord*, int);
// Original: arm9/main @ 0x020AC6B8; symbol: func_020ac6b8; size: 0x7C.
// Carries wrapped second increments into minutes and saturates the record at 9999:59:59.
extern "C" void TimeRecord_AddSecondsWithMinuteCarry(TimeRecord* p, int amount)
{
    p->seconds += amount;
    if (p->seconds > 59)
    {
        unsigned char minutes = p->seconds / 60;
        if (p->hours == 9999 && p->minutes + minutes > 59)
        {
            p->hours = 9999;
            p->minutes = 59;
            p->seconds = 59;
            return;
        }
        TimeRecord_AddMinutesWithHourCarry(p, minutes);
        p->seconds %= 60;
    }
}

