#include <globaldefs.h>
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" char* Event_GetObjectSession(int);
extern "C" void CutsceneActor_SetObjectSlot(void*, int);
// Original: arm9/ov001 @ 0x0215BF94; symbol: func_ov001_0215bf94; size: 0x40.
extern "C" int Script_SetBoundedRecordValueFromParameters(void* parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    int value = Script_ReadParameterAsInteger((char*)parameter + 8);
    char* record = Event_GetObjectSession(index);
    if (!record) return 0;
    CutsceneActor_SetObjectSlot(record, value);
    return 1;
}
