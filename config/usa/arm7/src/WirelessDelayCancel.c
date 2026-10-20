/* Cancel the wireless driver's scheduled alarm. */
#pragma dont_inline on
typedef unsigned long long WirelessDelayTicks;
typedef void (*WirelessDelayCallback)(void *);
typedef struct Alarm Alarm;
struct Alarm {
    WirelessDelayCallback completionProc; void *ppContext; unsigned int unknown_8;
    WirelessDelayTicks alarmTime; Alarm *pPrev, *pNext;
    WirelessDelayTicks alarmIntervalLength, alarmIntervalResidue;
};
typedef struct { unsigned char unknown000[0x634]; Alarm alarm; } WirelessDelayView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessDelayState (*(WirelessDelayView **)0x0380fff4)
extern void ARM7_CancelAlarm(Alarm *);
// Original: arm7/mainram @ 0x027EAEF8; symbol: func_027eaef8; size: 0x20.
void ARM7_CancelWirelessDelay(void)
{
    ARM7_CancelAlarm(&ARM7_WirelessDelayState->alarm);
}
