#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(void* state);
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov001 @ 0x02163248; symbol: func_ov001_02163248; size: 0x3C.
extern "C" int GameState_SetUnknown265FromParameter(IntegerParameterView* parameter) {
    void* state = _ZN9GameState11GetInstanceEv();
    signed char* field = (signed char*)GameState_ReadUnknownB0(state);
    if (field == 0)
        return 1;
    field[0x265] = ReadScriptParameterAsInteger(parameter) == 0;
    return 1;
}
