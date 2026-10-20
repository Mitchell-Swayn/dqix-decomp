#include <globaldefs.h>
ARM
extern "C" int Network_GetConnectionWorkspace(unsigned int mask);
extern "C" int Network_AdvanceConnectionShutdown(void *);
// Original: arm9/ov031 @ 0x02214334; symbol: System_SelectState11Or12FromPriorityRecord; size: 0x24.
// Tests the selected priority record at +0xA and returns state 0x12 or 0x11.
extern "C" int System_SelectState11Or12FromPriorityRecord(void) {
    unsigned char *state = (unsigned char *)Network_GetConnectionWorkspace(1);
    int value = Network_AdvanceConnectionShutdown(state + 0xa);
    return value == 1 ? 0x12 : 0x11;
}
