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
extern "C" {void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);void _ZN13SafeAllocator7DestroyEv(void*);void Memory_FreeThroughAllocatorUnion(void*,void*);void CharacterViewer_InitializeModelInstance(unsigned char*);extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];}
// Original: arm9/ov015 @ 0x0218F0C4; symbol: Memory_DestroyModeSelectedArenasAndResetOwner; size: 0x100.
// Destroys ten arenas for two modes or one arena otherwise, frees buffers and resets owner defaults.
extern "C" void CharacterViewer_DestroyModelInstanceResources(unsigned char* self){int i;unsigned char* heap=P(self,8);if(heap){if(self[0x1c]==0||self[0x1c]==1){i=0;while(i<10){void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(heap);_ZN13SafeAllocator7DestroyEv(heap);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);++i;heap+=20;}}else{void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(heap);_ZN13SafeAllocator7DestroyEv(P(self,8));Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);}Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(self,8));}if(P(self,0x20))Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(self,0x20));if(P(self,0x14))Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(self,0x14));if(P(self,0x24))Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(self,0x24));if(P(self,0x28))Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(self,0x28));if(P(self,4))P(self,4)[4]=0;CharacterViewer_InitializeModelInstance(self);}
