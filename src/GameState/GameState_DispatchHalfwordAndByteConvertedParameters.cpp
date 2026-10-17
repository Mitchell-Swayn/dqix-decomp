#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int GameState_GetIndexList();
extern "C" int ReadScriptParameterAsInteger(int);
extern "C" void func_020a0a08(int, int, int);
// Original: arm9/main @ 0x0209D974; symbol: func_0209d974; size: 0x50.
extern "C" int GameState_DispatchHalfwordAndByteConvertedParameters(int argument) {
    GameState::GetInstance();
    int state = GameState_GetIndexList();
    int x = ReadScriptParameterAsInteger(argument);
    int y = ReadScriptParameterAsInteger(argument + 8);
    func_020a0a08(state + 0xe04, (short)x, (signed char)y);
    return 1;
}
