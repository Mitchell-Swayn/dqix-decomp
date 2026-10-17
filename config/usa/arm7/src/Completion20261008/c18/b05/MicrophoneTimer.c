/* Select timer3's prescaler and reload value for a requested sample period.
 * Values at/above the largest representable timer period are rejected. */
#pragma dont_inline on
typedef struct {unsigned char prefix[0x34];unsigned short reload,prescaler;} MicrophoneTimerState;
extern MicrophoneTimerState ARM7_MicrophoneTimerState;
// Original: arm7/wram @ 0x03806920; symbol: ARM7_SetMicrophoneTimerPeriod.
int ARM7_SetMicrophoneTimerPeriod(unsigned int period)
{
 if(period<0x10000) {
  ARM7_MicrophoneTimerState.prescaler=0;
  ARM7_MicrophoneTimerState.reload=0x10000-period;
  return 1;
 }
 if(period<0x400000) {
  ARM7_MicrophoneTimerState.prescaler=1;
  ARM7_MicrophoneTimerState.reload=0x10000-(period>>6);
  return 1;
 }
 if(period<0x1000000) {
  ARM7_MicrophoneTimerState.prescaler=2;
  ARM7_MicrophoneTimerState.reload=0x10000-(period>>8);
  return 1;
 }
 if(period>=0x4000000)return 0;
 ARM7_MicrophoneTimerState.prescaler=3;
 ARM7_MicrophoneTimerState.reload=0x10000-(period>>10);
 return 1;
}
