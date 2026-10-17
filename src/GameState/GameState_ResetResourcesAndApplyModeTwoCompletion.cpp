#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" {void func_ov003_0217dc40(void*);void CleanupOverlayObjectAndOwnedAllocator(void*);void SetByteFieldAtOffset253ToOne(GameObject*);void* GameState_GetField3B0ObjectWithFlag4(GameState*);void Object_SetWordAtOffset23CTo1();void ClearMaskedFlagsAtOffset244(void*,int);void ClearWordAtOffset4MaskedBits(void*,int);
// Original: arm9/main @ 0x020DAEB0; symbol: func_020daeb0; size: 0x70.
void GameState_ResetResourcesAndApplyModeTwoCompletion(unsigned char* p){GameState* game=GameState::GetInstance();void* a=GameResources_GetInstance();void* q=*(void**)(p+12);if(q)func_ov003_0217dc40(q);CleanupOverlayObjectAndOwnedAllocator(p);SetByteFieldAtOffset253ToOne(game->GetUnknownGameObject());void* b=GameState_GetField3B0ObjectWithFlag4(game);Object_SetWordAtOffset23CTo1();ClearMaskedFlagsAtOffset244(b,2);ClearWordAtOffset4MaskedBits(a,0xc0);p[1]=1;}}
