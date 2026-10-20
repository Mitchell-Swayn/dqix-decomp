#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/BCFG.h>
ARM
struct ObjectArchiveLoadInfo;
struct Globals {unsigned pad0[3];char* state;unsigned pad1[4];int stage;unsigned pad2;int task;};
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
// Original data: arm9/ov025 @ 0x21ef9a8; symbol: data_ov025_021ef9a8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" {GameObject* GameState_GetObjectWithFlag100(GameState*,int);extern Globals CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;extern int CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage[];extern char Filesystem_SplitMatchedPathPrefixAndSuffix_PathDataPackLv5CharaMpGp2[],Combat_LoadCategoryArchiveOntoReplacementModel_TextMp0210BwChr[],Combat_LoadCategoryArchiveOntoReplacementModel_TextMp0209BwChr[];void* _ZN16BackgroundLoader11GetInstanceEv();void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);char* GameObject_GetLinkedActionDataWhenEnabled(char*);int Filesystem_QueueGP2LoadWithSingleOverlayFence(char*,char*);void Combat_ResetActionProcedureState(int*);unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);void* Combat_GetCurrentPresentationAllocator(char*);char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);void Combat_RegisterDeferredPresentationCleanup(unsigned char*,unsigned char*);void Object3D_ResetArchiveLoadInfo(unsigned*);bool _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void*,ObjectArchiveLoadInfo*,int(*)(BCFG::AnimationRecord*));}
struct PackedCategory {unsigned pad:4,category:5,rest:23;};
// Original: arm9/ov025 @ 0x021E66CC; symbol: func_ov025_021e66cc; size: 0x244.
// Chooses a category-specific archive and loads it onto object200 through the background task state machine.
extern "C" int Combat_LoadCategoryArchiveOntoReplacementModel(void* unused,char* record){
 GameState* game=GameState::GetInstance();void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.stage==0){
 char* object=(char*)GameState_GetObjectWithFlag100(game,*(unsigned short*)(*(char**)(record+16)+32));
 if(!object){Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);return 1;}
 char* buffer=GameObject_GetLinkedActionDataWhenEnabled(object);if(!buffer){Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);return 1;}
 unsigned category=((PackedCategory*)(buffer+8))->category;
 if(category==4)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.task=Filesystem_QueueGP2LoadWithSingleOverlayFence(Filesystem_SplitMatchedPathPrefixAndSuffix_PathDataPackLv5CharaMpGp2,Combat_LoadCategoryArchiveOntoReplacementModel_TextMp0210BwChr);
 else if(category==11)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.task=Filesystem_QueueGP2LoadWithSingleOverlayFence(Filesystem_SplitMatchedPathPrefixAndSuffix_PathDataPackLv5CharaMpGp2,Combat_LoadCategoryArchiveOntoReplacementModel_TextMp0209BwChr);
 else {Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);return 1;}
 CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.stage++;return 0;
 }
 if(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.stage==1){int task=CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.task;
 if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,task))return 0;
 if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)!=2){_ZN16BackgroundLoader10RemoveTaskEi(loader,task);Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);return 1;}
 unsigned info[8];unsigned size;void* file;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&file,&size);
 void* object=_ZN9GameState20GetGameObjectByIndexEi(game,200);if(!object){_ZN16BackgroundLoader10RemoveTaskEi(loader,task);Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);return 1;}
 void* allocator=Combat_GetCurrentPresentationAllocator(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.state);unsigned char* node=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)allocator,12);
 if(!node){_ZN16BackgroundLoader10RemoveTaskEi(loader,task);Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);return 1;}
 node[0]=0;*(unsigned short*)(node+2)=200;*(unsigned short*)(node+4)=0;Combat_RegisterDeferredPresentationCleanup((unsigned char*)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.state,node);
 Object3D_ResetArchiveLoadInfo(info);info[1]=(unsigned)file;info[2]=size;info[4]=1;info[3]=(unsigned)allocator;
 _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(object,(ObjectArchiveLoadInfo*)info,0);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task);Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);return 1;
 }return 0;
}
