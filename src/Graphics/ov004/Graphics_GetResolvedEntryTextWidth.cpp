#include <globaldefs.h>
ARM
struct State; struct T;
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" int TestValueEqualsTwelve(int);
extern "C" unsigned FindRecordValueByKeyOrZero(T*,int);
extern "C" void* func_ov011_021849c8(State*);
extern "C" void* func_ov023_021f6880(void*,unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void* OV023_GetEmbeddedField20(void*);
struct TextEntry { char pad[0x20]; const char* text; char pad2[0x12]; unsigned short parent; short key; char pad3[10]; unsigned char font:4; unsigned char other:4; };
// Original: arm9/ov004 @ 0x0215E4E8; symbol: func_ov004_0215e4e8; size: 0x8C.
extern "C" int Graphics_GetResolvedEntryTextWidth(State* self,unsigned id) {
 void* owner=func_ov011_021849c8(self);
 TextEntry* entry=(TextEntry*)func_ov023_021f6880(owner,id);
 if(!entry) return 0;
 const char* text=entry->text;
 if(!text) {
  void* parent=func_ov023_021f6880(owner,entry->parent);
  if(OV023_ReadHalfwordField04(parent)==4)
   text=(const char*)FindRecordValueByKeyOrZero((T*)OV023_GetEmbeddedField20(parent),entry->key);
 }
 int result=0;
 if(text) result=TextLayout_ComputeWidthWithGlyphSpacing(text,TestValueEqualsTwelve(entry->font));
 return result;
}
