#include <globaldefs.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" ARM int Script_ReadParameterAsInteger(IntegerParameterView *);
extern "C" void* Script_ResolveCharacterFromSignedSelector(int);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov023 @ 0x021EA71C; symbol: func_ov023_021ea71c; size: 0x60.
extern "C" int GameState_SetTypeThreeFieldFromCharacterFlag(IntegerParameterView *parameter) {
    _ZN9GameState11GetInstanceEv();
    void *character = Script_ResolveCharacterFromSignedSelector(Script_ReadParameterAsInteger(parameter));
    if (!character) return 0;
    unsigned int flags = *(unsigned int *)(*(void **)((char *)character + 0x130));
    int enabled = 0;
    if (flags & 2) enabled = 1;
    if (enabled != 0) Script_WriteIntegerReferenceOutput((char *)parameter + 8, 1);
    else Script_WriteIntegerReferenceOutput((char *)parameter + 8, 0);
    return 1;
}
