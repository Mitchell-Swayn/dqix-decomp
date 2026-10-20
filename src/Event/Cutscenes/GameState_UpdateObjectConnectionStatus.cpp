#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionManager(void);
extern "C" int Network_IsSessionActive(void *object);
extern "C" void Script_WriteIntegerReferenceOutput(void *object, int value);
// Original: arm9/ov001 @ 0x02161D8C; symbol: func_ov001_02161d8c; size: 0x24.
extern "C" int GameState_UpdateObjectConnectionStatus(void *object) {
    int connected = Network_IsSessionActive(Network_GetConnectionManager());
    Script_WriteIntegerReferenceOutput(object, connected);
    return 1;
}
