/* Advance software LED patterns and enqueue hardware-mode changes. */
#pragma dont_inline on
#include "PowerLed.h"
extern int ARM7_EnqueueSpiTask(int,unsigned int,unsigned short,...);
extern void ARM7_SetPowerLedPattern(int);
extern unsigned int ARM7_UnsignedDivide(unsigned int,unsigned int);
void ARM7_UpdatePowerLed(void)
{
 int pattern=ARM7_PowerLedPatternState.pattern;
 if(pattern==0) {
  if(ARM7_EnqueueSpiTask(3,100,1,1))ARM7_SetPowerLedPattern(1);
 }else if(pattern<4) {
  if(pattern!=ARM7_PowerLedMode)ARM7_EnqueueSpiTask(3,100,1,pattern);
 }else {
  const PowerLedPattern *entry=&ARM7_PowerLedPatterns[pattern-4];
  unsigned int step=ARM7_UnsignedDivide(ARM7_PowerLedPatternState.phase,entry->framesPerStep);
  int mode=(entry->bits&(0x8000000000000000ULL>>step))?1:2;
  if(++ARM7_PowerLedPatternState.phase>=entry->stepCount*entry->framesPerStep)ARM7_PowerLedPatternState.phase=0;
  if(mode!=ARM7_PowerLedMode)ARM7_EnqueueSpiTask(3,100,1,mode);
 }
}
