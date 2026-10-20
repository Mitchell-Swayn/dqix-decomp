#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct IntegerParameterView;
struct Entry { int kind,index,a,b; };
extern "C" void GameState_ClearObjectByIndex(GameState*,unsigned int);
extern "C" void _ZN8Object3D7DestroyEv(void*);
extern "C" void Event_ResetObjectBinding(Entry*);
extern "C" int Script_ResolveEventObjectIndex(int);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215B9C4; symbol: func_ov001_0215b9c4; size: 0xA0.
extern "C" int Script_DestroyIndexedGameObjectAndClearEntries(IntegerParameterView* parameter) {
GameState* state=GameState::GetInstance();
if(!state)return 0;
int index=Script_ResolveEventObjectIndex(Script_ReadParameterAsInteger(parameter));
GameObject* object=state->GetGameObjectByIndex(index);
if(!object)return 0;
_ZN8Object3D7DestroyEv(object);
GameState_ClearObjectByIndex(state,index);
if(*(Entry**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4)){
for(int i=0;i<32;++i){if((*(Entry**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4))[i].kind==1 && index==(*(Entry**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4))[i].index)Event_ResetObjectBinding(&(*(Entry**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4))[i]);}
}
return 1;
}
