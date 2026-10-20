#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" int Script_ReadParameterAsInteger(void*);extern "C" void* ActorPool_GetGlobalInstance();extern "C" unsigned* ActorPool_GetActiveSlot(unsigned**,unsigned);extern "C" unsigned short* Actor_GetPlacementDescriptor(void*);extern "C" void* ActorPool_GetSpriteResourceDirectory(void*);extern "C" unsigned Resource_FindActiveGraphicCacheEntryByName(void*,const char*);extern "C" void Resource_ReleaseNamedGraphicCacheEntry(void*,int);extern "C" void _ZN8Object3D7DestroyEv(void*);extern "C" void Object3D_InitializeExtendedRecord(void*);extern "C" void Object_ClearThreeWordsAndResetContainer(char*);extern "C" void ActorPool_SetSlot(int,unsigned,unsigned);extern "C" void Event_ResetObjectBinding(void*);extern "C" char ActorPool_ScriptDestroySlotFromEventReference_FormatSSpr[],EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
struct Ref{int type,id,unused1,unused2;};
// Original: arm9/ov001 @ 0x0215F740; symbol: Script_DestroyContainerSlotAndClearReferences; size: 0x114.
extern "C" int ActorPool_ScriptDestroySlotAndClearEventReferences(void* parameter){
int index=Script_ReadParameterAsInteger(parameter);if(index>=32)return 0;void* container=ActorPool_GetGlobalInstance();char* slot=(char*)ActorPool_GetActiveSlot((unsigned**)container,index);if(!slot)return 0;if(I(slot,20)){char* data=(char*)Actor_GetPlacementDescriptor(slot);void* table=ActorPool_GetSpriteResourceDirectory(container);char name[16];sprintf(name,ActorPool_ScriptDestroySlotFromEventReference_FormatSSpr,data+4);unsigned found=Resource_FindActiveGraphicCacheEntryByName(table,name);Resource_ReleaseNamedGraphicCacheEntry(table,found);}else if(V(slot,24)){_ZN8Object3D7DestroyEv(V(slot,24));Object3D_InitializeExtendedRecord(V(slot,24));}Object_ClearThreeWordsAndResetContainer(slot);ActorPool_SetSlot((int)container,index,0);if(V(EventGetObjectSession_UnknownRoleZeroInitializedStorage,4)){for(int i=0;i<32;++i){Ref* refs=(Ref*)V(EventGetObjectSession_UnknownRoleZeroInitializedStorage,4);if(refs[i].type==2||refs[i].type==6){if(index==refs[i].id)Event_ResetObjectBinding(&refs[i]);}}}return 1;
}
