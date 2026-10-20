#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int GameState_TestTransitionRequestFlags(void *, unsigned int);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x021626A4; symbol: func_ov001_021626a4; size: 0x40.
extern "C" int Ov001_UpdateNestedWordWhenFlagSet(void *object) {
    void *state = _ZN9GameState11GetInstanceEv();
    if (GameState_TestTransitionRequestFlags(state, 1)) {
        int value = GameState_TestTransitionRequestFlags(state, 1);
        Script_WriteIntegerReferenceOutput(object, value);
    }
    return 1;
}
