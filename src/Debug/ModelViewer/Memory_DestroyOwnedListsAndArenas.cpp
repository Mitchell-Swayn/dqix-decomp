#include <globaldefs.h>
ARM
struct RecordArray;
struct BufferPair { void* allocation; unsigned int other; };
struct Owner { unsigned char prefix[0xc4]; BufferPair groups[3][4]; };
extern "C" {
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];
void Memory_FreeThroughAllocatorUnion(void*, void*);
void CharacterViewer_DestroyModelInstanceResources(unsigned char*);
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
void _ZN13SafeAllocator7DestroyEv(void*);
void CharacterViewer_DestroyMenuCatalog(RecordArray*);
}
#define P(p,o) (*(unsigned char**)((p)+(o)))
// Original: arm9/ov015 @ 0x021933BC; symbol: func_ov015_021933bc; size: 0x13C.
// Releases a linked owner list, three four-entry buffer groups, arenas and record storage.
extern "C" void Memory_DestroyOwnedListsAndArenas(unsigned char* self) {
 unsigned char* node=P(self,0x2c);
 while(node) {
  CharacterViewer_DestroyModelInstanceResources(P(node,0));
  Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(node,0));
  unsigned char* old=node; node=P(node,4);
  Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,old);
 }
 for(int i=0;i<4;++i) {
  if(((Owner*)self)->groups[0][i].allocation) Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,((Owner*)self)->groups[0][i].allocation);
  if(((Owner*)self)->groups[1][i].allocation) Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,((Owner*)self)->groups[1][i].allocation);
  if(((Owner*)self)->groups[2][i].allocation) Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,((Owner*)self)->groups[2][i].allocation);
 }
 Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x88));
 Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x9c));
 Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0xb0));
 _ZN13SafeAllocator7DestroyEv(self+0x88);
 _ZN13SafeAllocator7DestroyEv(self+0x9c);
 _ZN13SafeAllocator7DestroyEv(self+0xb0);
 CharacterViewer_DestroyMenuCatalog((RecordArray*)(self+0x3c));
 if(P(self,0x84)){Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(self,0x84));P(self,0x84)=0;}
 if(P(self,0x344)){Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(self,0x344));P(self,0x344)=0;}
}
