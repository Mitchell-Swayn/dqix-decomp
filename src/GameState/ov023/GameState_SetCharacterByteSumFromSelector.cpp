#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void _ZN9GameState11GetInstanceEv(void);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
extern "C" void* ResolveCharacterBySignedSelector(int selector);
extern "C" void SetNestedSecondWordForTypeThree(void* output, int value);
// Original: arm9/ov023 @ 0x021EA6BC; symbol: func_ov023_021ea6bc; size: 0x60.
extern "C" int GameState_SetCharacterByteSumFromSelector(IntegerParameterView* parameter) {
    _ZN9GameState11GetInstanceEv();
    void* character = ResolveCharacterBySignedSelector(ReadScriptParameterAsInteger(parameter));
    if (character == 0)
        return 0;
    int sum = 0;
    for (int i = 0; i < 13; i++)
        sum += *(unsigned char*)(*(char**)((char*)character + 0x150) + (i & 0xff) + 0x186);
    SetNestedSecondWordForTypeThree((char*)parameter + 8, sum);
    return 1;
}
