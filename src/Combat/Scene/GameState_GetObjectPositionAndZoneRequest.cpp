#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021677D8; symbol: func_ov000_021677d8; size: 0x24.
extern "C" void *GameState_GetObjectPositionAndZoneRequest(void *state, int index) {
    if (index < 0)
        goto invalid;
    if (index >= 4)
        goto invalid;
    return (char *)state + 0x5910 + index * 16;
invalid:
    return 0;
}
