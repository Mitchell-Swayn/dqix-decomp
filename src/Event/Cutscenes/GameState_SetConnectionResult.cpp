#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager(void);
extern "C" int Network_IsSessionActive(void*);
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov001 @ 0x02160A00; symbol: func_ov001_02160a00; size: 0x48.
extern "C" int GameState_SetConnectionResult(void* output) {
    void* connection = Network_GetConnectionManager();
    int value;
    if (Network_IsSessionActive(connection) == 0)
        goto setone;
    if (Network_GetLocalMemberId((char*)connection) != 0)
        goto setzero;
setone:
    value = 1;
    goto done;
setzero:
    value = 0;
done:
    Script_WriteIntegerReferenceOutput(output, value);
    return 1;
}
