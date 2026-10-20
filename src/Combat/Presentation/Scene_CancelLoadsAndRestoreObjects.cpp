#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <World/Object3D.h>
#include <Graphics/LightingManager.h>
ARM
extern "C" {
unsigned BattleScene_GetActiveInstance();
char* BattleScene_ResolveCurrentActionRecord(char*);
void* Object_GetGlobalSixteenEntryDisplayState();
void Combat_ProcessDeferredPresentationCleanup(unsigned char*,int);
void RemoveMatchingNodeAndResetMatchingObjectSlots(int*,int);
void GameObject_EnableMotionUpdates(unsigned char*);
void GameState_ClearObjectByIndex(GameState*,int);
void SoundSfx_RestoreHeapAfterGroupPlayback(unsigned char*);
// Original data: arm9/ov025 @ 0x21ef990; symbol: data_ov025_021ef990.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern unsigned SceneCancelLoadsAndRestoreObjects_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov025 @ 0x21ef8dc; symbol: data_ov025_021ef8dc.
// Source-defined character literal. Text: "2". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "2".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern char SceneCancelLoadsAndRestoreObjects_Text2[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov025 @ 0x021E9558; symbol: func_ov025_021e9558; size: 0x220.
// Cancels pending loads and display operations, restores linked objects and fades lighting.
extern "C" void Scene_CancelLoadsAndRestoreObjects(unsigned char* owner)
{
 GameState* state=GameState::GetInstance();
 unsigned char* control=(unsigned char*)BattleScene_GetActiveInstance();
 char* records=BattleScene_ResolveCurrentActionRecord((char*)control);
 int* display=(int*)Object_GetGlobalSixteenEntryDisplayState();
 BackgroundLoader* loader=BackgroundLoader::GetInstance();
 for(int i=0;i<owner[0x582];++i) loader->RemoveTask(*(unsigned short*)(owner+0x584+i*2));
 owner[0x582]=0;
 if(*(int*)(owner+0x880)>=0) { loader->RemoveTask(*(int*)(owner+0x880));*(int*)(owner+0x880)=-1; }
 Combat_ProcessDeferredPresentationCleanup(owner,0);
 for(unsigned i=0;i<SceneCancelLoadsAndRestoreObjects_UnknownRoleZeroInitializedStorage;++i) RemoveMatchingNodeAndResetMatchingObjectSlots(display,i+100);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,4);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,32);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,33);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,27);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,25);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,26);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,31);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,33);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,34);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,35);
 RemoveMatchingNodeAndResetMatchingObjectSlots(display,36);
 SceneCancelLoadsAndRestoreObjects_UnknownRoleZeroInitializedStorage=0;
 for(char* p=*(char**)(records+0x10);p;p=*(char**)(p+0x30)) {
  GameObject* object=state->GetCombatantByIndex(*(unsigned short*)(p+0x20));
  if(object) { object->obj3D_.DisableFlag(0x800);GameObject_EnableMotionUpdates((unsigned char*)object); }
 }
 GameObject* object=state->GetGameObjectByIndex(200);
 if(object) {
  GameObject* parent=state->GetGameObjectByIndex(*(short*)((char*)object+2)*12+28);
  if(parent) parent->obj3D_.MakeVisible();
  object->obj3D_.Detach();
  GameState_ClearObjectByIndex(state,200);
 }
 ((Object3D*)(control+0x5954))->SetAnimationByName(SceneCancelLoadsAndRestoreObjects_Text2,1);
 ((Object3D*)(control+0x5a00))->SetAnimationByName(SceneCancelLoadsAndRestoreObjects_Text2,1);
 SoundSfx_RestoreHeapAfterGroupPlayback(Main_UnknownRoleZeroInitializedStorage);
 LightingManager::GetInstance()->BeginFade(0x1000,1000);
 *(int*)(owner+0x1c4)=0;
}
