#include <globaldefs.h>
ARM
// Original data: arm9/ov003 @ 0x217fe7f; symbol: data_ov003_0217fe7f.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a00000000.
// Observed span: 5 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" { int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*); int TextMarkup_AppendFrameTag(char*,int,int,int,int,int); int TextMarkup_AppendCursorTag(char*,int); int Text_AppendFormatString(char*,const char*); void* ResourceStringTable_GetTextByKey(void*,void*); extern char TextAppendIndexedRecordList_UnknownRoleInitializedBytes[]; }
// Original: arm9/ov003 @ 0x0215BE70; symbol: func_ov003_0215be70; size: 0xA8.
extern "C" void Graphics_AppendTwoIndexedLabelsWithCursor(unsigned char* object,char* text,int prefix) {
 if(text) {
  int cursor=*(signed char*)(object+0x586);
  if(prefix) TextMarkup_AppendFrameTag(text,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(text,cursor);
  for(int i=0;i<2;++i) {
   const char* label=(const char*)ResourceStringTable_GetTextByKey(object+0x64,(void*)(int)(short)(i+20));
   Text_AppendFormattedIntegerAndStringFragment(text,i,label);
   if(i!=1) Text_AppendFormatString(text,TextAppendIndexedRecordList_UnknownRoleInitializedBytes);
  }
 }
}
