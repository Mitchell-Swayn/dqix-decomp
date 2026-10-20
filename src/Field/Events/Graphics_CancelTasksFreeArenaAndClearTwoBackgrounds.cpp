#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void BackgroundLoader_RemovePrimaryAndThreeSecondaryTasks(void*);void* GameResources_GetInstance();void* SystemState_GetGlobalFlags();void GameResources_ClearSecondaryFlags(int,unsigned);void SystemState_ClearFlags(void*,unsigned);void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);void _ZN13SafeAllocator7DestroyEv(void*);void Memory_FreeThroughAllocatorUnion(void*,void*);void* memset(void*,int,unsigned);void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);void LoadToMainBG2CharacterData(const void*,unsigned,unsigned);void LoadToMainBG1ScreenData(const void*,unsigned,unsigned);void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];}
// Original: arm9/ov017 @ 0x021AAF08; symbol: Graphics_CancelTasksFreeArenaAndClearTwoBackgrounds; size: 0x108.
// Cancels outstanding tasks, frees allocated arena and clears two background character/screen planes.
extern "C" void Graphics_CancelTasksFreeArenaAndClearTwoBackgrounds(unsigned char* self){void* loader=_ZN16BackgroundLoader11GetInstanceEv();if(W(self,0x50)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x50));W(self,0x50)=-1;}if(P(self,24)){BackgroundLoader_RemovePrimaryAndThreeSecondaryTasks(P(self,24));P(self,24)=0;}void* resources=GameResources_GetInstance();void* globals=SystemState_GetGlobalFlags();GameResources_ClearSecondaryFlags((int)resources,128);SystemState_ClearFlags(globals,512);void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x24);_ZN13SafeAllocator7DestroyEv(self+0x24);if(allocation)Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);if(P(self,8)){memset(P(self,8),0,2048);_Z25CleanInvalidateCacheRangePKvj(P(self,8),2048);LoadToMainBG1CharacterData(P(self,8),0,32);LoadToMainBG2CharacterData(P(self,8),0,32);LoadToMainBG1ScreenData(P(self,8),0,2048);LoadToMainBG2ScreenData(P(self,8),0,2048);P(self,8)=0;}W(self,0x64)=0;}
