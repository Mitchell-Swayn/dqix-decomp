#include <globaldefs.h>
ARM
extern "C" unsigned long long _Z19GetCurrentTimestampv();
extern "C" void SleepOrCycleCurrentContextFromSharedState();
extern "C" void Unclassified_ResetAndInvokeStateCallback(char *);
struct Owner { char pad[0xa4]; char *pending; };
struct Root { int pad; Owner *owner; };
struct Callbacks { char pad[0x48]; int (*poll)(); };
extern "C" Root data_02111304;
extern "C" Callbacks data_ov031_0224c980;
// Original: arm9/ov031 @ 0x02203424; symbol: func_ov031_02203424; size: 0x88.
extern "C" void WaitForPendingFlagWithTimeout(void) {
    char *pending = data_02111304.owner->pending;
    if (!pending) return;
    if (*(unsigned char *)(pending + 9)) Unclassified_ResetAndInvokeStateCallback(pending);
    unsigned start = (unsigned)(_Z19GetCurrentTimestampv() >> 16);
    while (data_ov031_0224c980.poll() && *(unsigned char *)(pending + 8) &&
           (int)((unsigned)(_Z19GetCurrentTimestampv() >> 16) - start) < 39) {
        SleepOrCycleCurrentContextFromSharedState();
    }
    *(unsigned char *)(pending + 8) = 0;
}
