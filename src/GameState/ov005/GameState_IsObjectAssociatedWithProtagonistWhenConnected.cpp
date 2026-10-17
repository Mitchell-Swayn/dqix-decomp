#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameObject* GameState_FindIndexedObjectWithFlag1000(GameState*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" int ReadFieldAtOffset2D0(GameObject*);
// Original: arm9/ov005 @ 0x02157AE8; symbol: func_ov005_02157ae8; size: 0x8C.
extern "C" int GameState_IsObjectAssociatedWithProtagonistWhenConnected(void* unused,int index) {
GameState* state=GameState::GetInstance();
if(IsFirstWordNonzero(Object_GetGlobalConnectionState())){
GameObject* object=state->GetGameObjectByIndex(index);
if(!object)return 0;
unsigned short flags=*(unsigned short*)object;
int protagonist=GameState_ReadProtagonistObjectIndex(state);
if(flags&0x200){if(index!=protagonist)return 0;}
else if(flags&0x1000){if(protagonist!=ReadFieldAtOffset2D0(GameState_FindIndexedObjectWithFlag1000(state,index)))return 0;}
}
return 1;
}
