#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" void *GameState_GetSerializedProgressState(void);

// Original: arm9/ov001 @ 0x021609E4; symbol: func_ov001_021609e4; size: 0x1C.
extern "C" int GameState_ScriptSetUnknownProgressControlByteAt490(void *parameter) {
    int value = Script_ReadParameterAsInteger(parameter);
    unsigned char *global = (unsigned char *)GameState_GetSerializedProgressState();
    global[0x490] = (unsigned char)value;
    return 1;
}
