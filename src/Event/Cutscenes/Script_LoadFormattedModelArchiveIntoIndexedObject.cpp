#include <globaldefs.h>
ARM
struct ObjectArchiveLoadInfo {int unknown;const void* file;unsigned length;unsigned allocator;int flags,a,b,packageID;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" int Script_ResolveEventObjectIndex(int);
extern "C" void* FieldEvent_GetInEventResultDescriptor(void*);
extern "C" int sprintf(char*,const char*,...);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" unsigned Event_LoadFileIntoSharedScratch(const char*,void**);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN8Object3D10InitializeEv(void*);
extern "C" void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(void*,ObjectArchiveLoadInfo*);
extern "C" void GameState_SetIndexedObjectAndSlot(void*,int,void*);
extern "C" void _ZN8Object3D8SetScaleEiii(void*,int,int,int);
extern "C" bool _ZN8Object3D23SetBCFGAnimationByIndexEii(void*,int,int);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[],Script_LoadFormattedModelArchiveIntoIndexedObject_PathDataMapSChr[];

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov001 @ 0x0216066C; symbol: Script_LoadFormattedModelArchiveIntoIndexedObject; size: 0xFC.
extern "C" int Script_LoadFormattedModelArchiveIntoIndexedObject(char* params){void* game=_ZN9GameState11GetInstanceEv();_ZN16BackgroundLoader11GetInstanceEv();char* allocator=P(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage,0);int index=Script_ResolveEventObjectIndex(Script_ReadParameterAsInteger((IntegerParameterView*)params));char* resource=(char*)GameResources_GetInstance();char* named=(char*)FieldEvent_GetInEventResultDescriptor(P(resource,0x3734));char path[80];sprintf(path,Script_LoadFormattedModelArchiveIntoIndexedObject_PathDataMapSChr,named+4);_ZN16BackgroundLoader13AddLockGlobalEv();void* file;unsigned length=Event_LoadFileIntoSharedScratch(path,&file);if(!length){_ZN16BackgroundLoader16RemoveLockGlobalEv();return 0;}char* object=(char*)_ZN13SafeAllocator8AllocateEj((unsigned)allocator,0xac);_ZN8Object3D10InitializeEv(object);ObjectArchiveLoadInfo info;info.file=file;info.allocator=(unsigned)allocator;info.length=length;info.flags=1;_ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(object,&info);_ZN16BackgroundLoader16RemoveLockGlobalEv();GameState_SetIndexedObjectAndSlot(game,index,object);_ZN8Object3D8SetScaleEiii(object,266,266,266);_ZN8Object3D23SetBCFGAnimationByIndexEii(object,0,0);return 1;}