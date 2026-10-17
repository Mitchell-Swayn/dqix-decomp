#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" char* GetBounded1416ByteRecord(int);
extern "C" int Graphics_ClearStoppedAnimationAndTestEightSlots(char*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov001 @ 0x0215BF58; symbol: func_ov001_0215bf58; size: 0x3C.
extern "C" int GameState_SetNestedFlagForScriptRecord(IntegerParameterView* parameter) {
    char* record = GetBounded1416ByteRecord(ReadScriptParameterAsInteger(parameter));
    if (!record) return 0;
    int value = Graphics_ClearStoppedAnimationAndTestEightSlots(record) == 0;
    SetNestedSecondWordForTypeThree((char*)parameter + 8, value);
    return 1;
}
