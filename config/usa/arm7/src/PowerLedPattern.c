/* Select the software LED pattern and reset its phase. */
#pragma dont_inline on
#include "PowerLed.h"
void ARM7_SetPowerLedPattern(int pattern)
{
 if(pattern<=15) {
  ARM7_PowerLedPatternState.pattern=pattern;
  ARM7_PowerLedPatternState.phase=0;
 }
}
int ARM7_GetPowerLedPattern(void)
{
 return ARM7_PowerLedPatternState.pattern;
}
