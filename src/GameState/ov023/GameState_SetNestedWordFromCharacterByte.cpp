#include <globaldefs.h>
ARM

struct IntegerParameterView;
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void *ResolveCharacterBySignedSelector(int selector);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);

// Original: arm9/ov023 @ 0x021E9818; symbol: func_ov023_021e9818; size: 0x4C.
extern "C" int GameState_SetNestedWordFromCharacterByte(IntegerParameterView *parameters) {
    _ZN9GameState11GetInstanceEv();
    void *character = ResolveCharacterBySignedSelector(ReadScriptParameterAsInteger(parameters));
    if (character == 0) return 0;
    SetNestedSecondWordForTypeThree((char *)parameters + 0x10,
        *(unsigned char *)(*(char **)((char *)character + 0x150) +
        (ReadScriptParameterAsInteger((IntegerParameterView *)((char *)parameters + 8)) & 0xff) + 0x464));
    return 1;
}
