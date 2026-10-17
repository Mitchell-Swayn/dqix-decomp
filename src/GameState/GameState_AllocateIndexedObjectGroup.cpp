#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Object_GetGlobalConnectionState();
extern "C" void* GameResources_GetInstance();
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" char* _ZN9GameState15GetGrottoStructEv(void*);
extern "C" void Object_ResetFlagsAndEmbeddedRecordState(void*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void GameState_ClearObjectByIndex(void*,unsigned);
extern "C" void Object3D_InitializeExtendedMovementStateDefaults(char*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
extern "C" void GameState_SetIndexedObjectAndSlot(void*,int,void*);
struct Slot { unsigned short id; unsigned short a:2,used:1,b:13; char pad[12]; void *alloc1,*alloc2; char rest[0x300]; };
// Original: arm9/main @ 0x02028A54; symbol: func_02028a54; size: 0x158.
extern "C" int GameState_AllocateIndexedObjectGroup(Slot* slots,int id){
void* gs=_ZN9GameState11GetInstanceEv();
Object_GetGlobalConnectionState();GameResources_GetInstance();ReadGlobalValueAt020FB3F0();_ZN9GameState15GetGrottoStructEv(gs);
for(int i=0;i<4;i++)if(slots[i].id==id)return 0;
int index=-1;
for(int i=0;i<4;i++){if(!slots[i].used){index=i;break;}}
if(index<0)return 0;
Slot* slot=&slots[index];
Object_ResetFlagsAndEmbeddedRecordState(slot);
slot->used=1;slots[index].id=id;
_ZN13SafeAllocator5ResetEv(slot->alloc1);_ZN13SafeAllocator5ResetEv(slot->alloc2);
char* objects=_ZN13SafeAllocator8AllocateEj(slot->alloc1,0x1320);
int i=0;
if(!objects){for(;i<12;i++)GameState_ClearObjectByIndex(gs,i+(index*12+0x70));return 0;}
for(;i<12;i++){
Object3D_InitializeExtendedMovementStateDefaults(objects+i*0x198);
_ZN8Object3D10MakeHiddenEv(objects+i*0x198);
GameState_SetIndexedObjectAndSlot(gs,i+(index*12+0x70),objects+i*0x198);
}
return 1;
}
