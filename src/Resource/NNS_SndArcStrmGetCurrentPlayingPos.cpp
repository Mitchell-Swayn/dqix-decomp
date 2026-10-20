// Original: arm9/main @ 0x020BEC98; symbol: func_020bec98; size: 0x3c.
#include <globaldefs.h>
struct CounterRateRecord { char prefix[0xc4]; unsigned short rate; char gap[0x9a]; unsigned counter; };
// ARM9 main, original func_020bec98 at 0x020bec98.
// Proposed semantic name: ResourceHandle_ComputeScaledCounter.
extern "C" ARM unsigned NNS_SndArcStrmGetCurrentPlayingPos(CounterRateRecord *volatile *handle)
{
    if (!*handle) return 0;
    CounterRateRecord *record = *handle;
    return (unsigned long long)record->counter * 1000 / (unsigned)record->rate;
}
