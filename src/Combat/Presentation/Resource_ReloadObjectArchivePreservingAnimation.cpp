#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
namespace BCFG{struct AnimationRecord;}struct ObjectArchiveLoadInfo;extern "C" char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);extern "C" void* Combat_GetCurrentPresentationAllocator(char*);extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int _ZNK8Object3D23GetCurrentAnimationTimeEv(void*);extern "C" void Object3D_ResetArchiveLoadInfo(unsigned*);extern "C" unsigned Combat_GetPresentationAllocatorLevel(void*);extern "C" bool _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void*,ObjectArchiveLoadInfo*,int(*)(BCFG::AnimationRecord*));extern "C" void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);extern "C" void _ZN8Object3D23SetCurrentAnimationTimeEi(void*,int);extern "C" void Combat_RegisterDeferredPresentationCleanup(unsigned char*,unsigned char*);
// Original: arm9/ov025 @ 0x021e267c; symbol: Resource_ReloadObjectArchivePreservingAnimation; size 0x110.
extern "C" void Resource_ReloadObjectArchivePreservingAnimation(int index,int file,int option,int(*callback)(BCFG::AnimationRecord*)){void* game=_ZN9GameState11GetInstanceEv();void* allocator=Combat_GetCurrentPresentationAllocator(P(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage,12));void* object=_ZN9GameState20GetGameObjectByIndexEi(game,index);if(!object)return;char* node=_ZN13SafeAllocator8AllocateEj((unsigned)allocator,12);if(!node)return;char name[32];char* old=P(object,20);if(old)strcpy(name,old);int time=_ZNK8Object3D23GetCurrentAnimationTimeEv(object);unsigned info[8];Object3D_ResetArchiveLoadInfo(info);info[3]=(unsigned)allocator;info[1]=file;info[2]=option;info[4]=1;info[7]=Combat_GetPresentationAllocatorLevel(P(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage,12))+4;_ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(object,(ObjectArchiveLoadInfo*)info,callback);if(old){_ZN8Object3D18SetAnimationByNameEPKci(object,name,0);_ZN8Object3D23SetCurrentAnimationTimeEi(object,time);}B(node,0)=0;H(node,2)=index;H(node,4)=info[7];Combat_RegisterDeferredPresentationCleanup((unsigned char*)P(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage,12),(unsigned char*)node);}
