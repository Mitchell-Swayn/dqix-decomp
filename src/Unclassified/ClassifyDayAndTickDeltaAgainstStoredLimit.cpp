#include <globaldefs.h>
ARM
struct TimeState {unsigned char pad[12];int day;short tick,limit;};
// Original: arm9/main @ 0x020C965C; symbol: func_020c965c; size: 0x4C.
extern "C" int ClassifyDayAndTickDeltaAgainstStoredLimit(TimeState* state,int day,int tick){int deltaDay=day-state->day;int deltaTick=tick-state->tick;if(deltaDay<0 || (deltaDay==0 && deltaTick<0))return 0;if(deltaTick<0)deltaTick+=0x107;return deltaTick<=state->limit?1:2;}
