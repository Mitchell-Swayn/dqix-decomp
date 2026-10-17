#include <globaldefs.h>
#include <System/Timing.h>
struct State {unsigned duration;unsigned long long start;};extern "C" State data_02153628;
// Original: arm9/main @ 0x020E11E4; symbol: func_020e11e4; size: 0x58.
extern "C" ARM bool TestElapsedTimestampWithinDuration(){unsigned long long elapsed=GetCurrentTimestamp()-data_02153628.start;return (elapsed*64/33514)<data_02153628.duration;}
