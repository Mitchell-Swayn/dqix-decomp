#include <globaldefs.h>
ARM
extern "C" int Resource_ReleaseNamedGraphicCacheEntry(...);
extern "C" int Resource_FindActiveGraphicCacheEntryByName(...);
extern "C" int ActorPool_GetActiveSlot(...);
extern "C" int Object3D_InitializeExtendedRecord(...);
extern "C" int Object_ClearThreeWordsAndResetContainer(...);
extern "C" int ActorPool_GetGlobalInstance(...);
extern "C" int ActorPool_GetSpriteResourceDirectory(...);
extern "C" int Script_ReadParameterAsInteger(...);
extern "C" int Actor_GetPlacementDescriptor(...);
extern "C" int ActorPool_SetSlot(...);
extern "C" int _ZN8Object3D7DestroyEv(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
extern "C" char ActorPool_ScriptDestroySlotFromEventReference_FormatSSpr[];
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov001 @ 0x02161754; symbol: ScriptDestroyIndexedObjectAndClearContainerSlot.
extern "C" int ActorPool_ScriptDestroySlotFromEventReference(void*parameter){
int index=Script_ReadParameterAsInteger(parameter);if(index<0)return 0;struct Entry{int kind,id;char*first;char*object;};Entry*entries=(Entry*)P(EventGetObjectSession_UnknownRoleZeroInitializedStorage,4);char*entry=(char*)(entries+index);int type=W(entry,0);if(type!=6&&type!=2)return 0;int container=ActorPool_GetGlobalInstance();char*slot=C(ActorPool_GetActiveSlot(container,((Entry*)P(EventGetObjectSession_UnknownRoleZeroInitializedStorage,4))[index].id));if(!slot)return 0;if(P(slot,20)){char*name=C(Actor_GetPlacementDescriptor(slot));int table=ActorPool_GetSpriteResourceDirectory(container);char buffer[16];sprintf(buffer,ActorPool_ScriptDestroySlotFromEventReference_FormatSSpr,name+4);Resource_ReleaseNamedGraphicCacheEntry(table,Resource_FindActiveGraphicCacheEntryByName(table,buffer));}else if(P(slot,24)){_ZN8Object3D7DestroyEv(P(slot,24));Object3D_InitializeExtendedRecord(P(slot,24));}Object_ClearThreeWordsAndResetContainer(slot);ActorPool_SetSlot(container,((Entry*)P(EventGetObjectSession_UnknownRoleZeroInitializedStorage,4))[index].id,0);return 1;
}
