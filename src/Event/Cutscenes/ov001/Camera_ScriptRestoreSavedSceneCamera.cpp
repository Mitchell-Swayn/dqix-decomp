#include "GameState/GameState.h"
extern "C" int GameState_GetFieldAddress5CA4(int);
extern "C" void GameState_SetUnknown3b0(GameState*,void*);
struct PendingObjectState { void* unknown; void* pending; };
// Original: arm9/ov001 @ 0x0215F930; symbol: Camera_ScriptRestoreSavedSceneCamera; size: 0x38 (56).
// Restores the saved object pointer then consumes the pending slot; reports completion.
extern "C" ARM int Camera_ScriptRestoreSavedSceneCamera(){
 GameState* state=GameState::GetInstance();
 PendingObjectState* saved=(PendingObjectState*)GameState_GetFieldAddress5CA4((int)state);
 if(saved->pending){GameState_SetUnknown3b0(state,saved->pending);saved->pending=0;}
 return 1;
}
