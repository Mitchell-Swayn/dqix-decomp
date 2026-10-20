#include <globaldefs.h>
ARM
struct State;struct T;
struct FontNibble { unsigned char font:4; unsigned char other:4; };
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void* Menu_GetRecordMessageTable(void*);
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" int TextLookup_SelectFontTableForFont(int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
// Original: arm9/ov004 @ 0x0216AF24; symbol: func_ov004_0216af24; size: 0x8C.
extern "C" int Graphics_GetRecordTextWidth(State* self,unsigned index) {
void* owner=Menu_GetDisplayRecordRegistry(self);
unsigned char* rec=(unsigned char*)MenuRecordList_LocateByKey(owner,index);
if(!rec) return 0;
const char* text=*(const char**)(rec+0x20);
if(!text) {
void* parent=MenuRecordList_LocateByKey(owner,*(unsigned short*)(rec+0x36));
if(MenuRecord_GetType(parent)==4) {
T* table=(T*)Menu_GetRecordMessageTable(parent);
text=(const char*)MessageTextTable_FindTextById(table,*(short*)(rec+0x38));
}
}
int width=0;
if(text) width=TextLayout_ComputeWidthWithGlyphSpacing(text,TextLookup_SelectFontTableForFont(((FontNibble*)(rec+0x44))->font));
return width;
}
