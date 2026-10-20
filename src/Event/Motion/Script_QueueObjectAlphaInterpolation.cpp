#include <globaldefs.h>
ARM

extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" char *Event_GetObjectSession(int index);
extern "C" void Memory_AllocateAndInitializePoolNode(void *record, int first, int second);

// Original: arm9/ov001 @ 0x0215C5B4; symbol: func_ov001_0215c5b4; size: 0x48.
extern "C" int Script_QueueObjectAlphaInterpolation(void *parameters) {
    char *record = Event_GetObjectSession(Script_ReadParameterAsInteger(parameters));
    if (record == 0) {
        return 0;
    }
    int first = Script_ReadParameterAsInteger((char *)parameters + 8);
    int second = Script_ReadParameterAsInteger((char *)parameters + 0x10);
    Memory_AllocateAndInitializePoolNode(record, first, second);
    return 1;
}
