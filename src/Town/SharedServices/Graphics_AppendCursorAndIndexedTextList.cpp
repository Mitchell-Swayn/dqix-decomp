#include <globaldefs.h>
ARM
// Original data: arm9/ov003 @ 0x217ff3e; symbol: data_ov003_0217ff3e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" char GraphicsAppendCursorAndIndexedTextList_UnknownRoleInitializedBytes[];
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
// Original: arm9/ov003 @ 0x0215E13C; symbol: func_ov003_0215e13c; size: 0xB0.
extern "C" void Graphics_AppendCursorAndIndexedTextList(unsigned char* self,char* out,int styled) {
 if(out) {
  int cursor=*(signed char*)(self+0x3c1);
  if(styled) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(out,cursor);
  for(int i=0;i<self[0x3c0];i++) {
   const char* text=(const char*)ResourceStringTable_GetTextByKey(self+0x64,(void*)(unsigned)(self+i)[0x3bd]);
   Text_AppendFormattedIntegerAndStringFragment(out,i,text);
   if(i!=self[0x3c0]-1) Text_AppendFormatString(out,GraphicsAppendCursorAndIndexedTextList_UnknownRoleInitializedBytes);
  }
 }
}
