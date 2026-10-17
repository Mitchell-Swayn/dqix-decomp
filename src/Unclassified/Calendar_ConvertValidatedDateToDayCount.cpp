#include <globaldefs.h>

ARM
extern "C" {
struct Date { unsigned int year, month, day; int weekday; };
extern int data_020f2298[];
// Original: arm9/main @ 0x020CF8E4; symbol: func_020cf8e4; size: 0x94.
int Calendar_ConvertValidatedDateToDayCount(Date *date) {
    unsigned int year = date->year, month, day;
    if (year >= 100 || (month = date->month) < 1 || month > 12 || (day = date->day) < 1 || day > 31 || date->weekday >= 7 || month < 1 || month > 12) return -1;
    int days = (day - 1) + data_020f2298[month];
    if (month >= 3 && (year & 3) == 0) days++;
    return year*365 + days + ((year+3)>>2);
}
}
