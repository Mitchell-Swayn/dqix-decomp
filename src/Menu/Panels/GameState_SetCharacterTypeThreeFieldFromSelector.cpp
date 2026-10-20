#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
extern "C" void* Script_ResolveCharacterFromSignedSelector(int selector);
extern "C" void Script_WriteIntegerReferenceOutput(void* output, int value);
// Original: arm9/ov023 @ 0x021E98A0; symbol: func_ov023_021e98a0; size: 0x3C.
extern "C" int GameState_SetCharacterTypeThreeFieldFromSelector(IntegerParameterView* parameter) {
    _ZN9GameState11GetInstanceEv();
    void* character = Script_ResolveCharacterFromSignedSelector(Script_ReadParameterAsInteger(parameter));
    if (character == 0)
        return 0;
    unsigned short value = *(unsigned short*)((char*)*(void**)((char*)character + 0x130) + 6);
    Script_WriteIntegerReferenceOutput((char*)parameter + 8, value);
    return 1;
}
