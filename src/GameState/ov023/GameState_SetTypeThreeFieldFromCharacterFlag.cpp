#include <globaldefs.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" ARM int ReadScriptParameterAsInteger(IntegerParameterView *);
extern "C" void* ResolveCharacterBySignedSelector(int);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov023 @ 0x021EA71C; symbol: func_ov023_021ea71c; size: 0x60.
extern "C" int GameState_SetTypeThreeFieldFromCharacterFlag(IntegerParameterView *parameter) {
    _ZN9GameState11GetInstanceEv();
    void *character = ResolveCharacterBySignedSelector(ReadScriptParameterAsInteger(parameter));
    if (!character) return 0;
    unsigned int flags = *(unsigned int *)(*(void **)((char *)character + 0x130));
    int enabled = 0;
    if (flags & 2) enabled = 1;
    if (enabled != 0) SetNestedSecondWordForTypeThree((char *)parameter + 8, 1);
    else SetNestedSecondWordForTypeThree((char *)parameter + 8, 0);
    return 1;
}
