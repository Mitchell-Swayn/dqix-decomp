#include <globaldefs.h>
ARM
#pragma always_inline on
struct Node;struct List;
extern "C" {
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
Node* LinkedList_SelectAndRebuildNodes(List*,int,int,int,short,short*);
void TextCanvas_ClearGroupEntrySelection(unsigned char*,int);
void KrakPot_ResetRecipePagination(unsigned char*);
void Util_FindNodeAndUpdateSixteenEntryAnchor(void*,Node*);
void* KrakPot_GetRecipeAtPageRowClamped(void*,int);
void KrakPot_RefreshRecipePage(unsigned char*);
void Object_ConfigureSelectedDisplayPart(void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];
}
inline short SplitNodeIndex(unsigned char* self,short index){short row=index%16;self[0x388]=index/16;return row;}
// Original: arm9/ov006 @ 0x02159C64; symbol: func_ov006_02159c64; size: 0x14C.
// Toggles list mode and restores the selected node's page and row when eligible.
extern "C" void ToggleListModeAndPreserveSelectedNode(unsigned char* self) {
 short row;
 unsigned char* entry=(unsigned char*)KrakPot_GetRecipeAtPageRowClamped(self,(short)(*(short*)(self+0x36a)-0x29));
 if(entry) {
  if((((*(unsigned*)(entry+0x10)<<9)>>31))==0) {*(short*)(self+0x36a)=-1;*(short*)(self+0x35e)=-1;entry=0;}
  self[0x386]=self[0x386]==0;
  short count=0;
  LinkedList_SelectAndRebuildNodes((List*)(self+0x14c),(signed char)self[0x384],(signed char)self[0x385],self[0x386],16,&count);
  *(unsigned*)(self+0x30)=*(unsigned*)(self+0x2c)=*(unsigned*)(self+0x14c);
  if(!entry) entry=*(unsigned char**)(self+0x30);
  KrakPot_ResetRecipePagination(self);
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  unsigned char* p=*(unsigned char**)(self+0x30);
  short index=0;
  while(p) {if(p==entry) break; ++index;p=*(unsigned char**)(p+0x1c);}
  row=SplitNodeIndex(self,index);
  Util_FindNodeAndUpdateSixteenEntryAnchor(self,(Node*)entry);
  *(short*)(self+0x36a)=row+0x29;
  TextCanvas_ClearGroupEntrySelection(*(unsigned char**)(self+0x14),9);
  KrakPot_RefreshRecipePage(self);
  Object_ConfigureSelectedDisplayPart(self);
 }
}
