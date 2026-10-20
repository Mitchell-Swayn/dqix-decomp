#include <globaldefs.h>
struct Resources { char header[0x9c]; char allocator9c[0x1c]; };
extern "C" Resources* GameResources_GetInstance();
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* ActorPool_GetGlobalInstance();
extern "C" unsigned short* Zone3D_GetMainInstance();
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" int Menu_GetCompletedFieldCleanupPhaseMask(void*,unsigned);
extern "C" void Menu_MarkFieldCleanupPhasesCompleted(void*,unsigned);
extern "C" void ActorPool_CaptureActorSummaries(void*,unsigned);
extern "C" void Resource_ResetZoneAndAllocator();
extern "C" void GameState_ClearDisplayObjectsAndResetSlots(void*);
extern "C" void ActorPool_ResetLiveActorsAndResources(void*);
extern "C" void GameState_DestroyFieldObjectsAndResetAllocators(void*);
extern "C" void GameResources_SetSecondaryFlags(void*,unsigned);
extern "C" void Field_ReleaseChestPickupAndInteractionVisuals(void*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
// Original: arm9/ov011 @ 0x02184CC0; symbol: func_ov011_02184cc0; size: 0x124.
extern "C" unsigned Menu_ReleaseFieldResourcesForCleanupPhase(void* self) {
 Resources* resources=GameResources_GetInstance();
 void* owner=Resource_GetSharedLoadState();
 void* other=ActorPool_GetGlobalInstance();
 unsigned short* kind=Zone3D_GetMainInstance();
 switch(Menu_ReadScriptArgumentAsInteger(self)) {
 case 0:
  if(Menu_GetCompletedFieldCleanupPhaseMask(owner,1)) return 1;
  ActorPool_CaptureActorSummaries(other,*kind);
  Resource_ResetZoneAndAllocator();
  Menu_MarkFieldCleanupPhasesCompleted(owner,1); break;
 case 1:
  if(Menu_GetCompletedFieldCleanupPhaseMask(owner,2)) return 1;
  ActorPool_CaptureActorSummaries(other,*kind);
  GameState_ClearDisplayObjectsAndResetSlots(resources);
  ActorPool_ResetLiveActorsAndResources(other);
  GameState_DestroyFieldObjectsAndResetAllocators(resources);
  GameResources_SetSecondaryFlags(resources,8); GameResources_SetSecondaryFlags(resources,16);
  Menu_MarkFieldCleanupPhasesCompleted(owner,2); break;
 case 2:
  if(Menu_GetCompletedFieldCleanupPhaseMask(owner,4)) return 1;
  Field_ReleaseChestPickupAndInteractionVisuals(resources);
  _ZN13SafeAllocator5ResetEv(resources->allocator9c);
  Menu_MarkFieldCleanupPhasesCompleted(owner,4); break;
 }
 return 1;
}
