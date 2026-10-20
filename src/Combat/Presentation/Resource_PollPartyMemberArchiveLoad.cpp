#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" void* memset(void*,int,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void*,void*,void*);
extern "C" void PartyAppearance_FormatMemberResourceStem(unsigned,char*);
extern "C" char* Combat_GetCommandActorSnapshot(void*,int);
extern "C" void* BattleScene_GetActiveInstance();
extern "C" char* BattleScene_ResolveCurrentActionRecord(void*);
extern "C" void Combat_RegisterDeferredPresentationCleanup(unsigned char*,unsigned char*);
extern "C" char Resource_PollPartyMemberArchiveLoad_PathDataCharaSubS019BmChr[],Resource_PollPartyMemberArchiveLoad_FormatSbmChr[],Resource_PollPartyMemberArchiveLoad_PathDataPackLv5CharaMpGp2[];
// Original data: arm9/ov025 @ 0x21ef994; symbol: data_ov025_021ef994.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" char* CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage;
struct Nibbles {unsigned char low:4,high:4;};
struct Info {unsigned zero;void* file;unsigned size;void* allocator;unsigned a,b,c;volatile unsigned mode;};
inline int ValidIndex(int i){if(i>=0&&i<=3)return 1;return 0;}
// Original: arm9/ov025 @ 0x021EB46C; symbol: func_ov025_021eb46c; size: 0x290.
extern "C" int Resource_PollPartyMemberArchiveLoad(unsigned char* p) {
 char display[20],path[20];Info info;void* file;unsigned size;
 if(*(unsigned*)(p+0x1c4)&2) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 int loadedMember;
 void* allocator=*(void**)(p+0x10+p[0x30]*4);
 if(*(unsigned*)(p+0x1c8)==0) {
  char* record=BattleScene_ResolveCurrentActionRecord(BattleScene_GetActiveInstance());
  *(int*)(p+0x1cc)=-1;
  if(*(unsigned char*)(record+8)==1 && Combat_GetCommandActorSnapshot(record,0)) {
   int member=*(unsigned short*)(Combat_GetCommandActorSnapshot(record,0)+0x20);
   char* actor=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),member);
   if(ValidIndex(member) && actor) {
    char* data=*(char**)(actor+0x150);
    int kind=data?((Nibbles*)(data+0x56b))->low:0;
    if(kind==1) {
     sprintf(path,Resource_PollPartyMemberArchiveLoad_PathDataCharaSubS019BmChr);
     *(int*)(p+0x1cc)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,allocator);
    }else {
     PartyAppearance_FormatMemberResourceStem(member,display);
     sprintf(path,Resource_PollPartyMemberArchiveLoad_FormatSbmChr,display);
     *(int*)(p+0x1cc)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,Resource_PollPartyMemberArchiveLoad_PathDataPackLv5CharaMpGp2,path,allocator);
    }
   }
  }
  if(*(int*)(p+0x1cc)<0) {*(unsigned*)(p+0x1c4)&=~2;return 0;}
  ++*(unsigned*)(p+0x1c8);
 }else if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0x1cc))) {
  _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x1cc),&file,&size);
  if(file) {
   char* record=BattleScene_ResolveCurrentActionRecord(BattleScene_GetActiveInstance());
   if(Combat_GetCommandActorSnapshot(record,0)) {
    loadedMember=*(unsigned short*)(Combat_GetCommandActorSnapshot(record,0)+0x20);
    char* actor=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),loadedMember);
    if(actor) {
     char* node=_ZN13SafeAllocator8AllocateEj((unsigned)allocator,12);
     if(node) {
      info.file=file;info.zero=0;info.a=0;info.b=0;info.c=0;info.mode=0;info.allocator=allocator;info.size=size;
      info.mode=*(unsigned char*)(CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage+0x30)+4;
      _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(actor,&info,0);
      node[0]=0;*(short*)(node+2)=loadedMember;*(short*)(node+4)=info.mode;
      Combat_RegisterDeferredPresentationCleanup(p,(unsigned char*)node);
     }
    }
   }
  }
  _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x1cc));
  memset(p+0x1c8,0,16);
  *(unsigned*)(p+0x1c4)&=~2;
  return 0;
 }
 return 1;
 }
 return 0;
}
