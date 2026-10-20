#include <globaldefs.h>
ARM
struct State; struct T;
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" int TextLookup_SelectFontTableForFont(int);
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void* Menu_GetRecordMessageTable(void*);
struct TextEntry { char pad[0x20]; const char* text; char pad2[0x12]; unsigned short parent; short key; char pad3[10]; unsigned char font:4; unsigned char other:4; };
// Original: arm9/ov004 @ 0x0215E4E8; symbol: func_ov004_0215e4e8; size: 0x8C.
extern "C" int Graphics_GetResolvedEntryTextWidth(State* self,unsigned id) {
 void* owner=Menu_GetDisplayRecordRegistry(self);
 TextEntry* entry=(TextEntry*)MenuRecordList_LocateByKey(owner,id);
 if(!entry) return 0;
 const char* text=entry->text;
 if(!text) {
  void* parent=MenuRecordList_LocateByKey(owner,entry->parent);
  if(MenuRecord_GetType(parent)==4)
   text=(const char*)MessageTextTable_FindTextById((T*)Menu_GetRecordMessageTable(parent),entry->key);
 }
 int result=0;
 if(text) result=TextLayout_ComputeWidthWithGlyphSpacing(text,TextLookup_SelectFontTableForFont(entry->font));
 return result;
}
