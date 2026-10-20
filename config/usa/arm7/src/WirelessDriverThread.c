/* Return the driver thread embedded after the 24-byte wireless-state prefix.
 * The original driver-initialization routine at 0x027E8E7C passes the same
 * object to ARM7_CreateThread, establishing its ProcessorContext layout. */
#pragma dont_inline on
#include "ThreadContext.h"
typedef struct {
    unsigned char prefix[0x18];
    ProcessorContext thread;
} WirelessDriverThreadPrefix;
// Original: arm7/wram @ 0x0380FFF4; symbol: ARM7_WirelessDriverThreadState.
// Shared driver-state pointer; this declaration owns no initialized data or BSS.
extern WirelessDriverThreadPrefix *ARM7_WirelessDriverThreadState;
// Original: arm7/mainram @ 0x027E8EC8; symbol: ARM7_GetWirelessDriverThread; size: 0x14.
ProcessorContext *ARM7_GetWirelessDriverThread(void)
{
    return &ARM7_WirelessDriverThreadState->thread;
}
