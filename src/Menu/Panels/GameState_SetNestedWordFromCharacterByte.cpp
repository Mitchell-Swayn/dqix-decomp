#include <globaldefs.h>
ARM

struct IntegerParameterView;
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void *Script_ResolveCharacterFromSignedSelector(int selector);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);

// Original: arm9/ov023 @ 0x021E9818; symbol: func_ov023_021e9818; size: 0x4C.
extern "C" int GameState_SetNestedWordFromCharacterByte(IntegerParameterView *parameters) {
    _ZN9GameState11GetInstanceEv();
    void *character = Script_ResolveCharacterFromSignedSelector(Script_ReadParameterAsInteger(parameters));
    if (character == 0) return 0;
    Script_WriteIntegerReferenceOutput((char *)parameters + 0x10,
        *(unsigned char *)(*(char **)((char *)character + 0x150) +
        (Script_ReadParameterAsInteger((IntegerParameterView *)((char *)parameters + 8)) & 0xff) + 0x464));
    return 1;
}
