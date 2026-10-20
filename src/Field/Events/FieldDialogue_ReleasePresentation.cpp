#include <globaldefs.h>
ARM
extern "C" int BackgroundLoader_RemoveTasksDestroyAllocatorsAndResetGraphicsState(...);
extern "C" int ComputeGrottoAndContextDependentStateFlags(...);
extern "C" int GameResources_GetInstance(...);
extern "C" int Memory_FreeThroughAllocatorUnion(...);
extern "C" int TextContext_GetSharedInstance(...);
extern "C" int FieldDialogue_ResetPeerResponseTracking(...);
extern "C" int _Z16SetSubBrightnessP13GameResourcesii(...);
extern "C" int _ZN13SafeAllocator7DestroyEv(...);
extern "C" int _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" int _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" int _ZNK13SafeAllocator18GetSignedAllocatorEv(...);
extern "C" int FileCache_RestoreRomTablesIfSpaceAvailable(...);
extern "C" int Graphics_DestroyPanelResourcesAndAllocators(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021B8D80; symbol: DestroyOwnedTaskAllocatorsAndRestoreSubDisplay.
extern "C" void FieldDialogue_ReleasePresentation(char*self){
int resources=GameResources_GetInstance();if(W(self,288)>-1){int loader=_ZN16BackgroundLoader11GetInstanceEv();_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,288));}if(!B(self,311)){W(C(TextContext_GetSharedInstance()),140)=0;BackgroundLoader_RemoveTasksDestroyAllocatorsAndResetGraphicsState(self+48);void*allocation=(void*)_ZNK13SafeAllocator18GetSignedAllocatorEv(self+8);if(allocation){_ZN13SafeAllocator7DestroyEv(self+8);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);}}if(B(self,296)){Graphics_DestroyPanelResourcesAndAllocators(P(self,280));void*allocation=(void*)_ZNK13SafeAllocator18GetSignedAllocatorEv(self+28);if(allocation){_ZN13SafeAllocator7DestroyEv(self+28);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);}W(self,280)=0;volatile unsigned short*bg=(volatile unsigned short*)0x04001008;bg[0]=(bg[0]&~3)|1;bg[1]=(bg[1]&~3)|2;bg[2]&=~3;ComputeGrottoAndContextDependentStateFlags(0);_Z16SetSubBrightnessP13GameResourcesii(resources,0,15);}FieldDialogue_ResetPeerResponseTracking(self);FileCache_RestoreRomTablesIfSpaceAvailable();
}
