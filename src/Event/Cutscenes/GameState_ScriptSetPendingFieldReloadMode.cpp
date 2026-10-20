#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *);
extern "C" void GameState_SetPendingFieldReloadMode(int, unsigned char);
// Original: arm9/ov001 @ 0x021618D0; symbol: func_ov001_021618d0; size: 0x30.
extern "C" int GameState_ScriptSetPendingFieldReloadMode(IntegerParameterView *parameter) {
    void *gameState = _ZN9GameState11GetInstanceEv();
    GameState_SetPendingFieldReloadMode((int)gameState, (unsigned char)Script_ReadParameterAsInteger(parameter));
    return 1;
}
