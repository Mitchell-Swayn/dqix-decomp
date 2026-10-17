#include <globaldefs.h>
#pragma always_inline on
#include <Memory/SafeAllocator.h>
#include <System/Matrix.h>
struct LoadedContainer { unsigned short uniqueID,itemIDOrRank; unsigned short unk_4_0:2,lootType:2,containerType:3; short unused; Vector3i position; LoadedContainer* pNext; };
struct LocalContainerManager { unsigned unused; LoadedContainer* pContainerList_; unsigned short count; short tail; };
#include <System/Memory.h>
struct ZoneContainerEntry { unsigned short id,flags,lootType,type,present,enabled; unsigned reserved; Vector3i position; };
struct ZoneContainerName { unsigned short id; char name[24]; };
struct ZoneContainerPlacement { unsigned char type,pad,count,pad3; unsigned short* ids; int x,z; ZoneContainerPlacement* next; };
struct ZoneContainerOwner { char pad[0x754]; ZoneContainerPlacement* placements; char gap758[0x22]; unsigned char zoneCount,pad77b; ZoneContainerName* zones; unsigned char count; char gap781[0x237]; unsigned char dirty; };
extern "C" {
 void _ZN24LootableContainerManager5ResetEv(LocalContainerManager*);
 void _ZN24LootableContainerManager14ResetAllocatorEP13SafeAllocator(LocalContainerManager*,SafeAllocator*);
 void _ZN24LootableContainerManager18LoadZoneContainersEPKvjPKcP13SafeAllocator(LocalContainerManager*,const void*,unsigned,const char*,SafeAllocator*);
 void* Object_GetGlobalConnectionState();
 int TestActiveWordAndGlobalStateNonzero(void*);
 void ClearTwentyEntryBufferAndFlags(ZoneContainerOwner*);
 unsigned ReadGlobalValueAt020FB3F0();
 int fix32_Divide(int,int);
 void CopyNextEntryToCallerAndAdvanceCount(ZoneContainerOwner*,ZoneContainerEntry*);
}
// Original: arm9/main @ 0x02026780; symbol: func_02026780; size: 0x250.
// Load named zones' chest entries from treasure archive, apply placement offsets, retain standard chests.
extern "C" int LoadZoneChestEntriesFromArchive(ZoneContainerOwner* owner,const void* archive,unsigned archiveLength) {
 if(!owner->zoneCount || !owner->zones) return 0;
 if(TestActiveWordAndGlobalStateNonzero(Object_GetGlobalConnectionState())) { ClearTwentyEntryBufferAndFlags(owner);return 0; }
 ReadGlobalValueAt020FB3F0();
 char buffer[2048];
 SafeAllocator allocator;
 allocator.ResetAllocatorPointer();allocator.ResetAllocatorPointer();allocator.CreateTypeA(buffer,2048);
 owner->count=0;
 for(int i=0;i<owner->zoneCount;i++) {
  bool missing;
  int x=0,z=0;
  ZoneContainerPlacement* placement=owner->placements;
  missing=true;
  for(;placement && missing;placement=placement->next) {
   if(placement->type==1) {
    for(int j=0;j<placement->count && missing;j++) {
     if(placement->ids[j]==owner->zones[i].id) { x=placement->x;z=placement->z;missing=false; }
    }
   }
  }
  allocator.Reset();
  LocalContainerManager manager;
  _ZN24LootableContainerManager5ResetEv(&manager);
  _ZN24LootableContainerManager5ResetEv(&manager);
  _ZN24LootableContainerManager18LoadZoneContainersEPKvjPKcP13SafeAllocator(&manager,archive,archiveLength,owner->zones[i].name,&allocator);
  for(LoadedContainer* container=manager.pContainerList_;container;container=container->pNext) {
   ZoneContainerEntry entry;
   VectorizedMemset(&entry,0,sizeof(entry));
   entry.id=container->uniqueID;
   entry.flags=container->unk_4_0;
   entry.lootType=container->lootType;
   entry.type=container->containerType;
   entry.position=container->position;
   if(entry.type==0) {
    if(container->itemIDOrRank==0) entry.present=0; else entry.present=1;
    entry.enabled=entry.present;
    if(!missing) {
     entry.position.x=x+fix32_Divide(container->position.x,0x2666);
     entry.position.z=z+fix32_Divide(container->position.z,0x2666);
    }
    CopyNextEntryToCallerAndAdvanceCount(owner,&entry);
   }
  }
  _ZN24LootableContainerManager14ResetAllocatorEP13SafeAllocator(&manager,&allocator);
  _ZN24LootableContainerManager5ResetEv(&manager);
 }
 allocator.Destroy();owner->dirty=0;return 1;
}
