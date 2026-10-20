#include <globaldefs.h>
struct TimeRecord
{
    unsigned short hours;
    unsigned char minutes, seconds;
};
extern "C" void TimeRecord_AddHoursClampedTo9999(unsigned short*, int);
// Original: arm9/main @ 0x020AC644; symbol: func_020ac644; size: 0x74.
// Carries wrapped minute increments into hours and saturates the record at 9999:59:59.
extern "C" void TimeRecord_AddMinutesWithHourCarry(TimeRecord* p, int amount)
{
    p->minutes += amount;
    if (p->minutes > 59)
    {
        unsigned short hours = p->minutes / 60;
        if (p->hours + hours > 9999)
        {
            p->hours = 9999;
            p->minutes = 59;
            p->seconds = 59;
            return;
        }
        TimeRecord_AddHoursClampedTo9999(&p->hours, hours);
        p->minutes %= 60;
    }
}

