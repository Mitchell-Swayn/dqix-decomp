/* Initialize the touch slot protocol, tagged vertical alarms and SPI clock. */
#pragma dont_inline on
#include "TouchState.h"
#include "VerticalAlarm.h"
/* Both real allocations are cleared by the WRAM startup BSS loop. */
VerticalAlarm ARM7_TouchAlarms[4];
TouchState ARM7_TouchState;
extern int ARM7_IsVerticalAlarmInitialized(void);
extern void ARM7_InitializeVerticalAlarms(void);
extern void ARM7_ZeroInitializeVerticalAlarm(VerticalAlarm*);
extern void ARM7_SetVerticalAlarmTag(VerticalAlarm*,unsigned int);
extern void ARM7_ClockTouchSpiByte(void);
#define CONTROL (*(volatile unsigned short*)0x040001c0)
#define DATA (*(volatile unsigned short*)0x040001c2)
void ARM7_InitializeTouchState(void)
{
 int slot;
 unsigned int offset;
 VerticalAlarm *alarms;
 int alarm;
 ARM7_TouchState.operation=0;
 ARM7_TouchState.filterThreshold=20;
 ARM7_TouchState.retryThreshold=20;
 slot=0;
 do {ARM7_TouchRequest.slots[slot]=0;slot++;} while(slot<16);
 if(!ARM7_IsVerticalAlarmInitialized())ARM7_InitializeVerticalAlarms();
 alarms=ARM7_TouchAlarms;
 alarm=0;
 do {
  offset=alarm*sizeof(VerticalAlarm);
  ARM7_ZeroInitializeVerticalAlarm((VerticalAlarm*)((unsigned int)alarms+offset));
  ARM7_SetVerticalAlarmTag((VerticalAlarm*)((unsigned int)alarms+offset),0x54505641);
  alarm++;
 } while(alarm<4);
 while(CONTROL&0x80) {}
 CONTROL=0x8a01;
 DATA=0x84;
 while(CONTROL&0x80) {}
 ARM7_ClockTouchSpiByte();
 CONTROL=0x8201;
 ARM7_ClockTouchSpiByte();
}
