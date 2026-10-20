#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void *Script_ResolveCharacterFromSignedSelector(int);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9864; symbol: func_ov023_021e9864; size: 0x3C.
extern "C" int Script_WriteSelectedCharacterFieldToParameter(void *parameter) {
    _ZN9GameState11GetInstanceEv();
    void *character = Script_ResolveCharacterFromSignedSelector(Script_ReadParameterAsInteger(parameter));
    if (character == 0) return 0;
    unsigned short value = *(unsigned short *)(*(unsigned int *)((char *)character + 0x130) + 4);
    Script_WriteIntegerReferenceOutput((char *)parameter + 8, value);
    return 1;
}
