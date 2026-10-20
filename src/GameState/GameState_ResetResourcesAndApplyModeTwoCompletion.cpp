#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" {void GameState_ResetLoadResourcesAndOwnerSelection(void*);void CleanupOverlayObjectAndOwnedAllocator(void*);void GameObject_RequestMovementInputEnable(GameObject*);void* GameState_GetFieldOrbitCamera(GameState*);void Camera_EnableOrbitInput();void Camera_ClearFollowControlFlags(void*,int);void GameResources_ClearSecondaryFlags(void*,int);
// Original: arm9/main @ 0x020DAEB0; symbol: func_020daeb0; size: 0x70.
void GameState_ResetResourcesAndApplyModeTwoCompletion(unsigned char* p){GameState* game=GameState::GetInstance();void* a=GameResources_GetInstance();void* q=*(void**)(p+12);if(q)GameState_ResetLoadResourcesAndOwnerSelection(q);CleanupOverlayObjectAndOwnedAllocator(p);GameObject_RequestMovementInputEnable(game->GetUnknownGameObject());void* b=GameState_GetFieldOrbitCamera(game);Camera_EnableOrbitInput();Camera_ClearFollowControlFlags(b,2);GameResources_ClearSecondaryFlags(a,0xc0);p[1]=1;}}
