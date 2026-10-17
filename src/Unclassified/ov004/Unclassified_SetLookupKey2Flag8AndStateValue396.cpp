#include <globaldefs.h>
ARM
extern "C" void GameState_AppendValueAndSetNodeFlags(void *, unsigned int, unsigned int);
extern "C" void func_ov011_021848a0(void *, unsigned int);

// Original: arm9/ov004 @ 0x0215CC14; symbol: func_ov004_0215cc14; size: 0x2C.
extern "C" int Unclassified_SetLookupKey2Flag8AndStateValue396(void *state) {
    GameState_AppendValueAndSetNodeFlags(state, 2, 8);
    func_ov011_021848a0(state, 0x396);
    return 0;
}
