#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5b4; symbol: data_ov031_0224e5b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage[];
extern "C" void WirelessConnection_PollStatus(int value);
// Original: arm9/ov031 @ 0x02211DB0; symbol: func_ov031_02211db0; size: 0x58.
extern "C" int WirelessConnection_RequestCompletion(void) {
    unsigned char *context = *(unsigned char **)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage + 4);
    if (!context) return 0;
    if (*(unsigned *)context) {
        *(unsigned short *)(context + 4) = 3;
        WirelessConnection_PollStatus(3);
        context = *(unsigned char **)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage + 4);
        return context[0x0c] != 0;
    }
    return 0;
}
