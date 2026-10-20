#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[],Field_QueueContainerLootSpriteOrSpecialPresentation_FormatDataAniDC03DSpr[];extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void _ZN13SafeAllocator5ResetEv(void*);extern "C" void* GameResources_GetInstance();extern "C" void Field_LoadSharedPresentationEffect(void*,void*);extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Zone3D_GetMainInstance();extern "C" int GameState_ReadProtagonistObjectIndex(void*);extern "C" void _ZN6Zone3D21ReleaseChestsForOwnerEi(void*,int);extern "C" int sprintf(char*,const char*,...);extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
// Original: arm9/ov017 @ 0x021B5CF8; symbol: InitializeSpecialAllocatorOrQueueFormattedZoneResource; size: 0xCC.
extern "C" int Field_QueueContainerLootSpriteOrSpecialPresentation(char* self){char filename[128];if(U(self,0x12)==0x5617){B(self,0x54)=1;_ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x58);void* memory=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,0x4000);_ZN13SafeAllocator11CreateTypeAEPvj(self+0x58,memory,0x4000);_ZN13SafeAllocator5ResetEv(self+0x58);Field_LoadSharedPresentationEffect(GameResources_GetInstance(),self+0x58);}else{void* game=_ZN9GameState11GetInstanceEv();void* zone=Zone3D_GetMainInstance();_ZN6Zone3D21ReleaseChestsForOwnerEi(zone,(signed char)GameState_ReadProtagonistObjectIndex(game));sprintf(filename,Field_QueueContainerLootSpriteOrSpecialPresentation_FormatDataAniDC03DSpr,*(signed char*)(self+0x17),H(self,0x14));W(self,0x28)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(_ZN16BackgroundLoader11GetInstanceEv(),filename,0);}return 3;}
