#include <globaldefs.h>
#pragma optimize_for_size off
#pragma opt_common_subs off

// Original data: arm9/main @ 0x20f229c; symbol: data_020f229c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000001f0000003b0000005a0000007800000097000000b5000000d4000000f300000011010000300100004e010000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int CalendarConvertClampedDaysToDate_UnknownRoleInitializedBytes[12];

// Splits a day count into year (since epoch, 0-99), month, day-of-month and weekday.
// out: [0]=year, [1]=month (1-12), [2]=day of month, [3]=weekday (day count offset by 6, modulo 7).
// Original: arm9/main @ 0x020CF9F4; symbol: func_020cf9f4; size: 0x100.
extern "C" void Calendar_ConvertClampedDaysToDate(unsigned *out, int days) {
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
        if (days >= CalendarConvertClampedDaysToDate_UnknownRoleInitializedBytes[month]) {
            out[1] = month + 1;
            out[2] = days - CalendarConvertClampedDaysToDate_UnknownRoleInitializedBytes[month] + 1;
            return;
        }
    } while (--month >= 0);
}
