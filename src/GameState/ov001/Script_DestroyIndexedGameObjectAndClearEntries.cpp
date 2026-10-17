#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct IntegerParameterView;
struct Entry { int kind,index,a,b; };
extern "C" void GameState_ClearObjectByIndex(GameState*,unsigned int);
extern "C" void _ZN8Object3D7DestroyEv(void*);
extern "C" void InitializeFourWordState(Entry*);
extern "C" int ConvertNegativeIndexToBiasedMagnitude(int);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" unsigned char data_ov001_02165880[];
// Original: arm9/ov001 @ 0x0215B9C4; symbol: func_ov001_0215b9c4; size: 0xA0.
extern "C" int Script_DestroyIndexedGameObjectAndClearEntries(IntegerParameterView* parameter) {
GameState* state=GameState::GetInstance();
if(!state)return 0;
int index=ConvertNegativeIndexToBiasedMagnitude(ReadScriptParameterAsInteger(parameter));
GameObject* object=state->GetGameObjectByIndex(index);
if(!object)return 0;
_ZN8Object3D7DestroyEv(object);
GameState_ClearObjectByIndex(state,index);
if(*(Entry**)(data_ov001_02165880+4)){
for(int i=0;i<32;++i){if((*(Entry**)(data_ov001_02165880+4))[i].kind==1 && index==(*(Entry**)(data_ov001_02165880+4))[i].index)InitializeFourWordState(&(*(Entry**)(data_ov001_02165880+4))[i]);}
}
return 1;
}
