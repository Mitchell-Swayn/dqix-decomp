#include <globaldefs.h>
#include <System/ProcessorContext.h>
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
// Sleeps for the shared delay when nonzero; otherwise cycles the current context.
// Original: arm9/ov031 @ 0x02200264; symbol: func_ov031_02200264; size: 0x28.
extern "C" ARM void Network_YieldWithConfiguredPollDelay()
{
    unsigned int delay = NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[0x24 / 4];
    if (delay == 0) CycleCurrentPriorityContexts();
    else SleepCurrentContext(delay);
}
