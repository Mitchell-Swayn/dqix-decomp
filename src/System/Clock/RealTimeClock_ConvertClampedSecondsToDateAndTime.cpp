#include <globaldefs.h>
extern "C" void Calendar_ConvertClampedSecondsToHoursMinutesSeconds(void*,unsigned);
extern "C" void ConvertClampedDaysToCalendarDate(void*,unsigned);
// Original: arm9/main @ 0x020CFB74; symbol: func_020cfb74; size: 0x8C.
extern "C" void RealTimeClock_ConvertClampedSecondsToDateAndTime(void* a,void* b,long long value) {if(value<0)value=0;else if(value>0xbc19137fLL)value=0xbc19137fLL;Calendar_ConvertClampedSecondsToHoursMinutesSeconds(b,value%86400LL);ConvertClampedDaysToCalendarDate(a,value/86400LL);}
