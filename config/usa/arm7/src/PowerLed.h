#ifndef ARM7_POWER_LED_H
#define ARM7_POWER_LED_H
typedef struct {unsigned int phase;int pattern;} PowerLedPatternState;
typedef struct {unsigned long long bits;unsigned short stepCount,framesPerStep;} PowerLedPattern;
typedef char PowerLedPatternSizeCheck[sizeof(PowerLedPattern)==12?1:-1];
extern PowerLedPatternState ARM7_PowerLedPatternState;
extern const PowerLedPattern ARM7_PowerLedPatterns[12];
extern int ARM7_PowerLedMode;
#endif
