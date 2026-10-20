#include <globaldefs.h>
ARM
struct Flag {unsigned char low:1,copy:1,rest:6;};
extern "C" {
void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);
void* _ZN9GameState11GetInstanceEv();void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
void* Combat_GetIndexedActionTarget(void*,int);
void* Combat_GetCurrentCommandSlot(void*);void* Combat_GetCurrentActorSnapshotSlot(void*);char* Combat_GetCurrentTargetRecordSlot(char*);void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
void Combat_InitializeCommandRecord(unsigned char*);void Combat_InitializeTargetResultRecord(void*);
void Combat_AppendActorSnapshotToCommand(void*,void*);void Combat_AppendActionTargetRecord(void*,void*);void Combat_AppendTargetResultToCategoryList(void*,void*,int);
void Combat_PopulateResultFromCombatantSnapshot(void*,void*,void*,int,int,int,void*,void*,unsigned char);
void Combat_AppendResultMessage(void*,void*,int);
}
// Original: arm9/ov000 @ 0x0215B278; symbol: func_ov000_0215b278; size: 0x328.
extern "C" void Combat_CopySecondaryLinkedRecords(unsigned char* p,unsigned char* source){
 if(*(unsigned short*)source!=0x20b)return;
 for(int i=0;i<source[9];i++){
 unsigned char* record=(unsigned char*)Combat_GetIndexedActionTarget(source,i);if(!record)continue;
 int index=*(volatile short*)(record+0xe);
 unsigned char* actor=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);if(!actor)continue;
 unsigned char* owner=(unsigned char*)Combat_GetCurrentCommandSlot(p);if(!owner)continue;Combat_InitializeCommandRecord(owner);
 unsigned char* dest=(unsigned char*)Combat_GetCurrentActorSnapshotSlot(p);if(!dest)continue;memset(dest,0,0x30);*(short*)(dest+0x1c)=-1;*(int*)(dest+0x30)=0;
 unsigned char* list=(unsigned char*)Combat_GetCurrentTargetRecordSlot((char*)p);if(!list)continue;Combat_InitializeTargetResultRecord(list);
 *(short*)owner=0x3b1;
 *(short*)(dest+0x20)=*(short*)(record+0xe);
 *(unsigned short*)(dest+0x22)=**(unsigned short**)(actor+0x138);
 *(unsigned short*)(dest+0x24)=*(unsigned short*)(*(char**)(actor+0x138)+2);
 memcpy(list,record,0x24);
 Combat_AppendActorSnapshotToCommand(owner,dest);Combat_AppendActionTargetRecord(owner,list);owner[0xb]|=4;
 ++*(int*)(p+0x8e24);++p[0x8e00];++p[0x8e01];
 if(!((Flag*)(record+0x1d))->copy)continue;
 unsigned char* owner2=(unsigned char*)Combat_GetCurrentCommandSlot(p);if(!owner2)continue;Combat_InitializeCommandRecord(owner2);
 unsigned char* dest2=(unsigned char*)Combat_GetCurrentActorSnapshotSlot(p);if(!dest2)continue;memset(dest2,0,0x30);*(short*)(dest2+0x1c)=-1;*(int*)(dest2+0x30)=0;
 unsigned char* list2=(unsigned char*)Combat_GetCurrentTargetRecordSlot((char*)p);if(!list2)continue;Combat_InitializeTargetResultRecord(list2);
 unsigned char* node=(unsigned char*)Combat_ClearCurrentResultNodeSlot(p);if(!node)continue;memset(node,0,0x20);*(int*)(node+0x20)=0;
 *(short*)owner2=0x39c;
 *(short*)(dest2+0x20)=*(short*)(record+0xe);
 *(unsigned short*)(dest2+0x22)=**(unsigned short**)(actor+0x138);
 *(unsigned short*)(dest2+0x24)=*(unsigned short*)(*(char**)(actor+0x138)+2);
 owner2[0xb]|=4;
 short y=*(volatile short*)(*(char**)(actor+0x138)+2);short x=**(volatile short**)(actor+0x138);
 Combat_PopulateResultFromCombatantSnapshot(p,node,actor,0,x,y,0,0,0);
 Combat_AppendResultMessage(p,node,0x35);
 *(short*)(list2+0xe)=*(short*)(record+0xe);list2[0x17]=1;
 Combat_AppendTargetResultToCategoryList(list2,node,0);
 ++p[0x8e02];
 Combat_AppendActorSnapshotToCommand(owner2,dest2);Combat_AppendActionTargetRecord(owner2,list2);
 ++*(int*)(p+0x8e24);++p[0x8e00];++p[0x8e01];++p[0x8e02];
 }
}
