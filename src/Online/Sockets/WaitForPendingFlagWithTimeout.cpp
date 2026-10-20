#include <globaldefs.h>
ARM
extern "C" unsigned long long _Z19GetCurrentTimestampv();
extern "C" void Network_YieldWithConfiguredPollDelay();
extern "C" void Ssl_ResetConnectionAndFreeReceiveBuffer(char *);
struct Owner { char pad[0xa4]; char *pending; };
struct Root { int pad; Owner *owner; };
struct Callbacks { char pad[0x48]; int (*poll)(); };
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Root OSInitThread_UnknownRoleZeroInitializedStorage_Variant2;
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Callbacks NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02203424; symbol: func_ov031_02203424; size: 0x88.
extern "C" void WaitForPendingFlagWithTimeout(void) {
    char *pending = OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.owner->pending;
    if (!pending) return;
    if (*(unsigned char *)(pending + 9)) Ssl_ResetConnectionAndFreeReceiveBuffer(pending);
    unsigned start = (unsigned)(_Z19GetCurrentTimestampv() >> 16);
    while (NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.poll() && *(unsigned char *)(pending + 8) &&
           (int)((unsigned)(_Z19GetCurrentTimestampv() >> 16) - start) < 39) {
        Network_YieldWithConfiguredPollDelay();
    }
    *(unsigned char *)(pending + 8) = 0;
}
