#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
struct Tree;
// Original data: arm9/ov023 @ 0x21fff24; symbol: data_ov023_021fff24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" void MenuRecord_ResetHeader(void*);extern "C" Tree* Menu_FindSessionArenaById(Tree*,unsigned);extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" unsigned MenuSelectionGridInitializeAndAllocateEntryTable_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov023 @ 0x021f8cf4; symbol: Object_InitializeTypeSevenTileBuffer.
extern "C" int MenuSelectionGrid_InitializeAndAllocateEntryTable(unsigned char* s,Tree* owner,unsigned key,unsigned tree,int width,int height){
MenuRecord_ResetHeader(s);U(s,4)=7;U(s,6)=key;U(s,8)=tree;U(s,10)=0;W(s,16)=0;U(s,36)=width;U(s,38)=height;U(s,40)=0;U(s,42)=0;W(s,44)=0;W(s,48)=0;W(s,52)=0;W(s,56)=1;W(s,28)=2;
Tree* node=Menu_FindSessionArenaById(owner,U(s,8));if(!node)return 0;
unsigned size=2*width*height;P(s,32)=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)node+4,size);if(!P(s,32))return 0;memset(P(s,32),0,size);
U(s,60)=0;U(s,62)=0;U(s,64)=0;U(s,66)=0;U(s,68)=0;U(s,70)=0;U(s,72)=0;U(s,74)=0;U(s,76)=0;U(s,78)=0;U(s,80)=0;U(s,82)=0;U(s,84)=0;U(s,86)=0;U(s,88)=0;U(s,90)=0;MenuSelectionGridInitializeAndAllocateEntryTable_UnknownRoleZeroInitializedStorage=500;U(s,92)=0;U(s,94)=1;s[96]=1;s[97]=1;s[98]=0;return 1;
}
