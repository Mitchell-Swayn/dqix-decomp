/* Select the software LED pattern and reset its phase. */
#pragma dont_inline on
typedef struct {unsigned int phase;int pattern;} PowerLedPatternState;
extern PowerLedPatternState ARM7_PowerLedPatternState;
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
