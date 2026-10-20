#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct GameResources;
extern "C" GameResources *GameResources_GetInstance();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void FieldEvent_SetContinuationEventId(unsigned char *p, unsigned short value);
// Original: arm9/ov001 @ 0x0215F9DC; symbol: func_ov001_0215f9dc; size: 0x34.
extern "C" int Event_ScriptSetUnknownSceneControlValueAt11A(IntegerParameterView *parameter) {
    unsigned char *target = *(unsigned char **)((unsigned char *)GameResources_GetInstance() + 0x3734);
    unsigned short value = (unsigned short)Script_ReadParameterAsInteger(parameter);
    FieldEvent_SetContinuationEventId(target, value);
    return 1;
}
