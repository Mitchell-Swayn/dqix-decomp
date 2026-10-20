#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" char* Menu_FindSessionArenaById(void*,unsigned);extern "C" unsigned Graphics_ComputeAlignedTilePayloadBytes(void*,void*,unsigned);extern "C" char* Menu_GetDisplayRecordRegistry(void*);extern "C" unsigned Ov023_FindRangeStart(char*,unsigned);extern "C" void Util_InsertNodeByAscendingKey(void*,void*);extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);extern "C" void Sprite_LoadCellsPalettesAndAnimationTables(void*,void*,void*,unsigned);extern "C" void Sprite_SelectAnimationAndResetFrame(void*,int);
// Original: arm9/ov023 @ 0x021FB9C4; symbol: AllocateTilePayloadRangeAndInitializeAnimation; size: 0xac.
extern "C" void MenuSprite_AllocateTileRangeAndLoadAnimation(char* self,void* owner,void* bytes,unsigned length){
if(!bytes||!length)return;char* node=Menu_FindSessionArenaById(owner,*(unsigned short*)(self+8));if(!node)return;unsigned size=Graphics_ComputeAlignedTilePayloadBytes(self+32,bytes,length);char* tree=Menu_GetDisplayRecordRegistry(owner);unsigned start=Ov023_FindRangeStart(tree,size);W(self,0x94)=start;W(self,0x98)=start+size;Util_InsertNodeByAscendingKey(tree,self+0x94);W(self,0x58)=start;_ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(node+4);Sprite_LoadCellsPalettesAndAnimationTables(self+32,node+4,bytes,length);Sprite_SelectAnimationAndResetFrame(self+32,1);_ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(node+4);
}
