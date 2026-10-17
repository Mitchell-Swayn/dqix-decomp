#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" void *ResolveCharacterBySignedSelector(int);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021E9864; symbol: func_ov023_021e9864; size: 0x3C.
extern "C" int func_ov023_021e9864(void *parameter) {
    _ZN9GameState11GetInstanceEv();
    void *character = ResolveCharacterBySignedSelector(ReadScriptParameterAsInteger(parameter));
    if (character == 0) return 0;
    unsigned short value = *(unsigned short *)(*(unsigned int *)((char *)character + 0x130) + 4);
    SetNestedSecondWordForTypeThree((char *)parameter + 8, value);
    return 1;
}
