#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" char* Event_GetObjectSession(int);
extern "C" int Graphics_ClearStoppedAnimationAndTestEightSlots(char*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov001 @ 0x0215BF58; symbol: func_ov001_0215bf58; size: 0x3C.
extern "C" int GameState_SetNestedFlagForScriptRecord(IntegerParameterView* parameter) {
    char* record = Event_GetObjectSession(Script_ReadParameterAsInteger(parameter));
    if (!record) return 0;
    int value = Graphics_ClearStoppedAnimationAndTestEightSlots(record) == 0;
    Script_WriteIntegerReferenceOutput((char*)parameter + 8, value);
    return 1;
}
