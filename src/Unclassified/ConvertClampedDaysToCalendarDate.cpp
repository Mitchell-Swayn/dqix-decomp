#include <globaldefs.h>
#pragma optimize_for_size off
#pragma opt_common_subs off

extern "C" int data_020f229c[12];

// Splits a day count into year (since epoch, 0-99), month, day-of-month and weekday.
// out: [0]=year, [1]=month (1-12), [2]=day of month, [3]=weekday (day count offset by 6, modulo 7).
// Original: arm9/main @ 0x020CF9F4; symbol: func_020cf9f4; size: 0x100.
extern "C" void ConvertClampedDaysToCalendarDate(unsigned *out, int days) {
    if (days < 0) {
        days = 0;
    }
    if (days > 36524) {
        days = 36524;
    }
    out[3] = (days + 6) % 7;

    unsigned year = 0;
    do {
        int previous = days;
        int yearLength;
        if ((year & 3) == 0) yearLength = 365 + 1;
        else yearLength = 365;
        days -= yearLength;
        if (days < 0) { days = previous; break; }
        year++;
    } while (year < 99);
    out[0] = year;

    if (days > 365) {
        days = 365;
    }
    if ((year & 3) == 0) {
        if (days < 60) {
            unsigned month;
            if (days < 31) {
                month = 1;
            } else {
                days -= 31;
                month = 2;
            }
            out[1] = month;
            out[2] = days + 1;
            return;
        }
        days -= 1;
    }
    int month = 11;
    do {
        if (days >= data_020f229c[month]) {
            out[1] = month + 1;
            out[2] = days - data_020f229c[month] + 1;
            return;
        }
    } while (--month >= 0);
}
