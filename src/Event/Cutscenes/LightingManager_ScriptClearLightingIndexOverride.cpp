#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" char *_ZN15LightingManager11GetInstanceEv(void);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
// Original: arm9/ov001 @ 0x021603B0; symbol: func_ov001_021603b0; size: 0x28.
extern "C" int LightingManager_ScriptClearLightingIndexOverride(IntegerParameterView *parameter) {
    char *manager = _ZN15LightingManager11GetInstanceEv();
    Script_ReadParameterAsInteger(parameter);
    *(unsigned int *)(manager + 0x90) = 0;
    return 1;
}
