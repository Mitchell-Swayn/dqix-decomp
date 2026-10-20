#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov001 @ 0x021608E8; symbol: func_ov001_021608e8; size: 0x1C.
extern "C" int TextWindow_ScriptSetReadyActionType(IntegerParameterView *parameter) {
    int value = Script_ReadParameterAsInteger(parameter);
    *(int *)(TextContext_GetSharedInstance() + 0x99c) = value;
    return 1;
}
