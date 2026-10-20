#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/BCFG.h>
#include <std_library_functions.h>
ARM
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[]; extern char Combat_QueueActorCheerArchive_PathDataCharaCsOuenChr[];
void* Combat_GetCurrentPresentationAllocator(char*);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
bool Filesystem_SplitMatchedPathPrefixAndSuffix(char*,char*,char*);
int _ZN16BackgroundLoader22GetLoadedFileInArchiveEPKcS1_PPvPj(void*,const char*,const char*,void**,unsigned*);
int _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
int Combat_DispatchSelectionProcedure(void*,void*,int,int*);
void Resource_ReloadObjectArchivePreservingAnimation(int,int,int,int(*)(BCFG::AnimationRecord*));
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void Resource_RemoveIndexedHalfword(void*,int);
}
// Original: arm9/ov025 @ 0x021E83C4; symbol: func_ov025_021e83c4; size: 0x14C.
// Resolves an archive path, reloads selected objects, and removes the completed load task.
extern "C" int Combat_ReloadSelectedObjectsWithActorCheerArchive(unsigned char* action,void* selection,int unused,void* context) {
 char path[80]; char archive[80],inner[80]; int ids[8]; void* file;unsigned length;
 GameState* state=GameState::GetInstance();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 Combat_GetCurrentPresentationAllocator(*(char**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage+12));
 unsigned char* object=(unsigned char*)GameState_GetObjectWithFlag100(state,*(unsigned short*)(*(char**)((char*)selection+16)+32));
 struct ActorFlag {unsigned char flag:1; unsigned char rest:7;};
 unsigned flag=((ActorFlag*)(*(char**)(object+0x150)+0x49c))->flag;
 int marker=0x6d; if(flag==1)marker=0x77;
 sprintf(path,Combat_QueueActorCheerArchive_PathDataCharaCsOuenChr,marker);
 file=0; int task;
 if(Filesystem_SplitMatchedPathPrefixAndSuffix(path,archive,inner))task=_ZN16BackgroundLoader22GetLoadedFileInArchiveEPKcS1_PPvPj(loader,archive,inner,&file,&length);
 else task=_ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(loader,path,&file,&length);
 if(file) {int count=Combat_DispatchSelectionProcedure(context,selection,action[8],ids);if(count>0)for(int i=0;i<count;i++)Resource_ReloadObjectArchivePreservingAnimation(ids[i],(int)file,length,0);}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
 Resource_RemoveIndexedHalfword(*(void**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage+12),task);
 return 1;
}
