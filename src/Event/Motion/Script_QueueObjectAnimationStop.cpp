#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" char *Event_GetObjectSession(int i);
extern "C" unsigned Event_QueueObjectAnimationStop(void);
// Original: arm9/ov001 @ 0x0215C70C; symbol: func_ov001_0215c70c; size: 0x24.
extern "C" unsigned Script_QueueObjectAnimationStop(void *parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    if (!Event_GetObjectSession(index))
        return 0;
    Event_QueueObjectAnimationStop();
    return 1;
}
