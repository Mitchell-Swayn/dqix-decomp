// Original: arm9/main @ 0x020CFC00; symbol: func_020cfc00; size: 0xBC.
// SDK C reconstruction: RTC_GetDayOfWeek using Zeller's congruence.
// Reference: RushRE/SonicRushAdventure-Decomp@b449036259b8eff92ceb2b226474149bcf8a0a30
// lib/NitroSDK/src/rtc/ARM9/rtc_convert.c, RTC_GetDayOfWeek.
#pragma optimize_for_size off
struct RTCDate { unsigned year, month, day, week; };
typedef int RTCWeek;
extern "C" RTCWeek RTC_GetDayOfWeek(RTCDate *date)
{
    int cent;
    int year  = (int)(2000 + date->year);
    int month = (int)date->month;
    int day   = (int)date->day;

    month -= 2;

    if (month < 1)
    {
        month += 12;
        --year;
    }

    cent = year / 100;
    year %= 100;
    return (RTCWeek)(((26 * month - 2) / 10 + day + year + year / 4 + cent / 4 + 5 * cent) % 7);
}