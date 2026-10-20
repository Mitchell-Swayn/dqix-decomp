#include <globaldefs.h>
ARM
extern "C" int GlobalState_IsCurrentObjectFieldSeven(void);
extern "C" int YssdClient_SendLengthPrefixedPacket(void *);
// Original: arm9/ov031 @ 0x0221032C; symbol: func_ov031_0221032c; size: 0x2C.
extern "C" int YssdClient_SendPacketWhenConnected(void *object) {
    int result = -0x38;
    if (GlobalState_IsCurrentObjectFieldSeven() != 0)
        result = YssdClient_SendLengthPrefixedPacket(object);
    return result;
}
