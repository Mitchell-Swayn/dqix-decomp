#pragma opt_rebuildlogicals off
#include <GameState/GameState.h>
#include <World/WorldPlacementSource.h>
#include <World/Object3D.h>
#include <Resource/BCFG.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
struct Placement {int index;Vector3i position;int time;Placement* next;};
struct Owner {unsigned int unknown[2];Object3D* object;Placement* placements;};
extern "C" char* Zone3D_GetMainInstance();extern "C" void* Object_GetGlobalSixteenEntryDisplayState();extern "C" int Zone3D_FindGroundHeightBelowPosition(char*,Vector3i*);
// Original: arm9/main @ 0x0208F168; symbol: func_0208f168; size: 0x204.
extern "C" void WorldPlacement_InstantiateAvailableTimedPlacements(Owner* owner,SafeAllocator* allocator) {
 if(!allocator)return;
 char* zone=Zone3D_GetMainInstance();char* map=*(char**)(zone+8);
 WorldPlacementSource* source=WorldPlacementSource::GetInstance();
 if(!map)return;
 switch(source->IsMapEligible(map+5)) { case 0: return; default: break; }
 if(!owner->object)return;
 owner->object->SetBCFGAnimationByIndex(0,0);
 BCFG* config=owner->object->GetCurrentAnimationConfig();if(!config)return;
 BCFG::AnimationRecord* animation=config->GetAnimationRecord(0);if(!animation)return;
 GameState* state=GameState::GetInstance();
 WorldPlacementSource::PersistentState* states=state->placementStates_;
 WorldPlacementSource::Record* record=source->head;
 Object_GetGlobalSixteenEntryDisplayState();state->GetProtagonist();unsigned char ordinal=0;
 for(;record;record=record->next,++ordinal) {
  int index=record->index;WorldPlacementSource::PersistentState* persistent=states+index;
  if(persistent->available) {
   record->state=persistent;record->flags=persistent->flags;
   int count=persistent->count;if(index>=98)count=8;
   for(int i=0;i<count;++i) {
    unsigned int packed=*(volatile unsigned int*)persistent;unsigned int bit=1<<i;
    if(((packed<<7)>>24) & bit) {
     Placement* node=(Placement*)allocator->Allocate(24);if(!node)return;
     node->index=i+ordinal*8;
     int start=animation->startTime;node->time=start+rand()%(animation->endTime-start);
     record->positions[i].y=Zone3D_FindGroundHeightBelowPosition(zone,&record->positions[i]);node->position=record->positions[i];
     if(!owner->placements){owner->placements=node;node->next=0;}
     else {Placement* tail=owner->placements;while(tail->next)tail=tail->next;tail->next=node;node->next=0;}
    }
   }
  }
 }
}
