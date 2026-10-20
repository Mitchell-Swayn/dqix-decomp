/* Select the software LED pattern and reset its phase. */
#pragma dont_inline on
#include "PowerLed.h"
// Original: arm7/wram @ 0x038064CC; symbol: ARM7_SetPowerLedPattern.
void ARM7_SetPowerLedPattern(int pattern)
{
 if(pattern<=15) {
  ARM7_PowerLedPatternState.pattern=pattern;
  ARM7_PowerLedPatternState.phase=0;
 }
}
// Original: arm7/wram @ 0x038064E8; symbol: ARM7_GetPowerLedPattern.
int ARM7_GetPowerLedPattern(void)
{
 return ARM7_PowerLedPatternState.pattern;
}
