#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" char* GameState_GetIndexList(GameState*);extern "C" unsigned ReadScriptParameterAsInteger(char*);extern "C" void SetNestedSecondWordForTypeThree(char*,unsigned);extern "C" unsigned ReadSignedByteValueForNonnegativeHalfwordKey(char*,int);
// Original: arm9/main @ 0x0209D9C4; symbol: func_0209d9c4; size: 0x44.
extern "C" int Script_ReadKeyValueFromGameStateOffsetE04(char* p){char* state=GameState_GetIndexList(GameState::GetInstance());int id=ReadScriptParameterAsInteger(p);unsigned value=ReadSignedByteValueForNonnegativeHalfwordKey(state+0xe04,(short)id);SetNestedSecondWordForTypeThree(p+8,value);return 1;}
