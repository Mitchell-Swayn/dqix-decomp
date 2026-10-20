#include <globaldefs.h>
#include <World/Object3D.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
ARM
extern "C" {
void* Object_GetGlobalSixteenEntryDisplayState();
void* GameState_ReadUnknownB0(GameState*);
void* _ZN9GameState20GetGameObjectByIndexEi(GameState*, int);
void RemoveMatchingNodeAndResetMatchingObjectSlots(int*,int);
unsigned BattleScene_GetActiveInstance();
void* BattleScene_GetCamera(unsigned char*);
void GameState_SetUnknown3b0(GameState*,void*);
void _ZN8Object3D7DestroyEv(void*);
void GameState_ClearObjectByIndex(GameState*,int);
}
struct PendingOperation { unsigned char type, threshold; unsigned short index, package; PendingOperation* next; };
// Original: arm9/ov025 @ 0x021E8BC4; symbol: func_ov025_021e8bc4; size: 0x12C.
// Drains threshold-qualified operations, preserving animation selection and time after package removal.
extern "C" void Combat_ProcessDeferredPresentationCleanup(unsigned char* owner,int threshold) {
 char animation[40];
 if (*(PendingOperation**)(owner+0x1d8)) {
 GameState* state=GameState::GetInstance();
 int* display=(int*)Object_GetGlobalSixteenEntryDisplayState();
 GameState_ReadUnknownB0(state);
 PendingOperation* p=*(PendingOperation**)(owner+0x1d8);
 for (;p && threshold<=p->threshold;p=p->next) {
 switch(p->type) {
 case 0: {
 char* object=(char*)_ZN9GameState20GetGameObjectByIndexEi(state,p->index);
 if(object) {
 if (*(char**)(object+0x14)) strcpy(animation,*(char**)(object+0x14));
 unsigned char selection=object[0x19]; int time=*(int*)(object+0x1c);
 ((Object3D*)object)->RemoveAnimationPackageByID(p->package);
 ((Object3D*)object)->SetAnimationByName(animation,selection);
 ((Object3D*)object)->SetCurrentAnimationTime(time);
 } break; }
 case 1: RemoveMatchingNodeAndResetMatchingObjectSlots(display,p->package);break;
 case 2: break;
 case 3: GameState_SetUnknown3b0(state,BattleScene_GetCamera((unsigned char*)BattleScene_GetActiveInstance()));break;
 case 4: {void* object=_ZN9GameState20GetGameObjectByIndexEi(state,p->index);if(object) {_ZN8Object3D7DestroyEv(object);GameState_ClearObjectByIndex(state,p->index);}break;}
 }
 }
 *(PendingOperation**)(owner+0x1d8)=p;
 }
}
