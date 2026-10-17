#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
extern "C" void* ResolveCharacterBySignedSelector(int selector);
extern "C" void SetNestedSecondWordForTypeThree(void* output, int value);
// Original: arm9/ov023 @ 0x021E98A0; symbol: func_ov023_021e98a0; size: 0x3C.
extern "C" int GameState_SetCharacterTypeThreeFieldFromSelector(IntegerParameterView* parameter) {
    _ZN9GameState11GetInstanceEv();
    void* character = ResolveCharacterBySignedSelector(ReadScriptParameterAsInteger(parameter));
    if (character == 0)
        return 0;
    unsigned short value = *(unsigned short*)((char*)*(void**)((char*)character + 0x130) + 6);
    SetNestedSecondWordForTypeThree((char*)parameter + 8, value);
    return 1;
}
