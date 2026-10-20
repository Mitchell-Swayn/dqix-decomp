#include <globaldefs.h>
ARM
struct GameState;struct Object3D;struct Owner;struct MapObjectFilterState;struct UnknownResetRecord;
struct Snapshot {int first,second,third,fourth;unsigned kind;unsigned char appearance,pad[3];unsigned flags;unsigned char changed,appearanceChanged,suppress,padding;};
// Original data: arm9/main @ 0x20fdcb0; symbol: data_020fdcb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Snapshot GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[4];
// Original data: arm9/main @ 0x20fdc60; symbol: data_020fdc60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" void PartyStatus_ResetMemberSnapshot(UnknownResetRecord*);
extern "C" void PartyStatus_InitializePanelSlide(unsigned char*);
extern "C" unsigned short GameObject_GetCurrentVocationLevel(int);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" bool SystemState_TestAnyFlags(const unsigned*,unsigned);
extern "C" void BackgroundLoader_ClearLoadStateAndRemoveTasks(unsigned char*);
extern "C" void ResourceLoader_PollAndBuildLoadedSubDisplayResources(unsigned char*);
extern "C" void BackgroundLoader_AdvanceActiveFileTask(Owner*);
extern "C" void BackgroundLoader_DispatchEnabledState(char*);
extern "C" void WorldMap_ApplyObjectIdFilterRules(MapObjectFilterState*,int);
// Original: arm9/main @ 0x02022DC8; symbol: func_02022dc8; size: 0x29C.
// Tracks party appearance/status changes, resets unused records, and advances loaders.
extern "C" void BackgroundLoader_RefreshPartySnapshotsAndDispatch(unsigned char* self) {
 GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
 for(int i=0;i<4;++i) if(!_ZN9GameState21GetPartyMemberByIndexEi(state,i)) PartyStatus_ResetMemberSnapshot((UnknownResetRecord*)&GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[i]);
 int count=self[0x75c];
 if(count) while(count<4) {PartyStatus_InitializePanelSlide(PartyStatusResetMappedMemberAnimation_UnknownRoleZeroInitializedStorage+count*20);++count;}
 for(int i=0;i<self[0x75c];++i) {
  int index=(self+0x758)[i];
  unsigned char mask=1<<index;
  Snapshot* previous=&GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[index];
  char* member=(char*)_ZN9GameState21GetPartyMemberByIndexEi(state,index);
  if(!member || !(self[0x55d]&mask)) continue;
  char* status=*(char**)(member+0x130);
  char* details=*(char**)(member+0x134);
  int first=*(unsigned short*)(status+4),third=*(unsigned short*)(details+0x30),second=*(unsigned short*)(status+6),fourth=*(unsigned short*)(details+0x32);
  unsigned kind=*(unsigned*)(*(char**)(member+0x150)+0x950);
  unsigned char appearance=GameObject_GetCurrentVocationLevel((int)member);
  unsigned flags=**(unsigned**)(member+0x130);
  previous->appearanceChanged|=(previous->kind!=kind);
  previous->appearanceChanged|=(previous->appearance!=appearance);
  previous->appearanceChanged|=(previous->flags!=flags);
  if(previous->first>=0) {
   previous->changed|=previous->appearanceChanged;
   previous->changed|=(previous->first!=first);
   previous->changed|=(previous->second!=second);
   previous->changed|=(previous->third!=third);
   previous->changed|=(previous->fourth!=fourth);
  }
  previous->first=first;previous->second=second;previous->third=third;previous->fourth=fourth;previous->kind=kind;previous->appearance=appearance;previous->flags=flags;
  if(previous->first>0) *(unsigned*)(member+0x18c)&=~1;
  if(previous->suppress) {previous->changed=0;previous->suppress=0;}
 }
 if(SystemState_TestAnyFlags((const unsigned*)SystemState_GetGlobalFlags(),1)) BackgroundLoader_ClearLoadStateAndRemoveTasks(self);
 else {
  if(self[0x9c5] && self[0x764]) ResourceLoader_PollAndBuildLoadedSubDisplayResources(self);
  if(self[0x9b8]) BackgroundLoader_AdvanceActiveFileTask((Owner*)self);
  if(self[0x9c3]) BackgroundLoader_DispatchEnabledState((char*)self);
  else WorldMap_ApplyObjectIdFilterRules((MapObjectFilterState*)self,1);
 }
}
