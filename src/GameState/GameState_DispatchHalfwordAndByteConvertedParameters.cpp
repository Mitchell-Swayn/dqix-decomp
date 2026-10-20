#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int GameState_GetIndexList();
extern "C" int Script_ReadParameterAsInteger(int);
extern "C" void Inventory_RemoveItemCountAndCompact(int, int, int);
// Original: arm9/main @ 0x0209D974; symbol: func_0209d974; size: 0x50.
extern "C" int GameState_DispatchHalfwordAndByteConvertedParameters(int argument) {
    GameState::GetInstance();
    int state = GameState_GetIndexList();
    int x = Script_ReadParameterAsInteger(argument);
    int y = Script_ReadParameterAsInteger(argument + 8);
    Inventory_RemoveItemCountAndCompact(state + 0xe04, (short)x, (signed char)y);
    return 1;
}
