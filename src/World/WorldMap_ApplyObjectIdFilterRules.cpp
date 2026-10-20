#include "GameState/GameState.h"
#include "World/ZonePredicates.h"
struct MapObjectFilter { unsigned char configured,style,count,padding; unsigned short* ids; int valueA,valueB; MapObjectFilter* next; };
struct MapObjectFilterState { unsigned char unknown0[0x754]; MapObjectFilter* filters; unsigned char unknown758[0x33e]; unsigned char pendingMask; };
struct MapLocationContext { unsigned short zoneId; unsigned char unknown2[6]; void* active; unsigned char embedded[1]; };
struct FilteredMapObject { unsigned short flags; unsigned char unknown2[0x18a]; unsigned int filterFlags; };
extern "C" {
FilteredMapObject* GameState_GetObjectWithFlag100(GameState*,int);
MapLocationContext* Zone3D_GetMainInstance();
void GameObject_SetMapMarkerCoordinates(void*,int,int);
void GameObject_SetMapMarkerCategory(void*,int);
}
// Applies pending ID rules to the first four game objects, with special-zone grouping and boss selection.
// The embedded-address check preserves the original context validity test; its broader type is unknown.
// Original: arm9/main @ 0x02026BDC; symbol: func_02026bdc; size: 0x2E0.
extern "C" void WorldMap_ApplyObjectIdFilterRules(MapObjectFilterState* self,int consume) {
 GameState* state=GameState::GetInstance();
 for(int i=0;i<4;++i) {
  if(!state->GetGameObjectByIndex(i))continue;
  if(!(self->pendingMask&(1<<i)))continue;
  GameResources_GetInstance();
  FilteredMapObject* object=GameState_GetObjectWithFlag100(state,i);
  if(!object)continue;
  MapLocationContext* location=Zone3D_GetMainInstance();
  if(!location->embedded || !location->active)return;
  if((object->flags&0x1000) && (location->zoneId==10000 || location->zoneId==10100)) {
   object->filterFlags&=~8;
   continue;
  }
  MapObjectFilter* rule;
  int found=0;
  if(consume)self->pendingMask&=~(1<<i);
  rule=self->filters;
  int id=((Object3D*)object)->GetField06();
  if(location->zoneId==10000 || location->zoneId==10100) {
   if(id<20000 || id>29999)id=id/100*100;
   while(rule && !found) {
    for(int j=0;j<rule->count && !found;++j) {
     int candidate=rule->ids[j];
     if(candidate<20000 || candidate>29999)candidate=candidate/100*100;
     if(candidate==id) {
      object->filterFlags|=8;
      if(!rule->configured)object->filterFlags&=~0x10;
      else {
       object->filterFlags|=0x10;
       GameObject_SetMapMarkerCoordinates(object,rule->valueA,rule->valueB);
       GameObject_SetMapMarkerCategory(object,rule->style);
      }
      found=1;
     }
    }
    rule=rule->next;
   }
  } else if(IsGrottoBossFloorZone(id)) {
   GameObject* selected=state->GetUnknownGameObject();
   if(selected) {
    int selectedId=selected->obj3D_.GetField06();
    if(selectedId==id) {found=1;object->filterFlags|=8;object->filterFlags&=~0x10;}
   }
  } else {
   while(rule && !found) {
    for(int j=0;j<rule->count && !found;++j) {
     int candidate=rule->ids[j];

     if(id==candidate) {
      object->filterFlags|=8;
      if(!rule->configured)object->filterFlags&=~0x10;
      else {
       object->filterFlags|=0x10;
       GameObject_SetMapMarkerCoordinates(object,rule->valueA,rule->valueB);
       GameObject_SetMapMarkerCategory(object,rule->style);
      }
      found=1;
     }
    }
    rule=rule->next;
   }
  }
  if(!found)object->filterFlags&=~8;
 }
}
