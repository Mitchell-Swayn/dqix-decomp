#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
// Original data: arm9/ov000 @ 0x21834f8; symbol: data_ov000_021834f8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000300000001000000040000000200000005000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" int TextAppendSixObjectRecordLabels_UnknownRoleInitializedBytes[];
// Original: arm9/ov000 @ 0x02176500; symbol: func_ov000_02176500; size: 0x134.
extern "C" void Text_AppendSixObjectRecordLabels(unsigned char* self,char* out,int prefix) {
 if(!out || !*(void**)(self+4)) return;
 unsigned char* obj=(unsigned char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),*(int*)(self+0x4c));
 if(!obj) return;
 int special=0;
 if(((unsigned int)*(unsigned char*)(*(unsigned char**)(obj+0x138)+0x3b)<<28)>>31) special=1;
 int cursor=*(signed char*)(self+0x1c);
 if(prefix) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 for(int i=0;i<6;i++) {
  int id=TextAppendSixObjectRecordLabels_UnknownRoleInitializedBytes[i];
  if(!special && id==5) TextMarkup_AppendPaletteTag(out,3);
  const char* text=(const char*)ResourceStringTable_GetTextByKey(*(void**)(self+4),(void*)(int)(short)(id+0x7534));
  Text_AppendFormattedIntegerAndStringFragment(out,id,text);
  if(i==5) break;
  if(i&1) Text_AppendFormatString(out,(const char*)ResourceStringTable_GetTextByKey(*(void**)(self+4),0));
  else TextMarkup_AppendXPositionTag(out,0x45);
  TextMarkup_AppendPaletteTag(out,15);
 }
}
