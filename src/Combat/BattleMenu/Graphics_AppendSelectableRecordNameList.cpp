#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedXYPair(char*,int,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendLineTag(char*,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void* ActionData_GetGlobalTables();
extern "C" void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int BattleMenu_HasTouchSelectionChanged(void*);
// Original: arm9/ov000 @ 0x0217A2DC; symbol: func_ov000_0217a2dc; size: 0x238.
extern "C" void Graphics_AppendSelectableRecordNameList(char* self,void*,char* out) {
 const char* empty=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,(void*)31);
 const char* separator=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,0);
 int cursor=*(signed char*)(self+0x1d6d);
 Text_AppendFormatString(out,separator);
 if(*(unsigned char*)(self+0x1d81)) {
  if(BattleMenu_HasTouchSelectionChanged(self)) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
  void* manager=ActionData_GetGlobalTables();
  if(!manager) return;
  for(int i=0;i<*(signed char*)(self+0x1a);i++) {
   int color=3;
   if(i==cursor) color=5;
   TextMarkup_AppendPaletteTag(out,color);
   unsigned id=*(unsigned short*)(self+0x10+i*2);
   if(!id) Text_AppendFormatString(out,empty);
   else {
    unsigned* record=(unsigned*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)manager,(short)id);
    if(!record) continue;
    Text_AppendFormatString(out,(const char*)record[0]);
   }
   if(i!=*(signed char*)(self+0x1a)-1) Text_AppendFormatString(out,separator);
  }
 } else {
  if(BattleMenu_HasTouchSelectionChanged(self)) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(out,cursor);
  void* manager=ActionData_GetGlobalTables();
  if(!manager) return;
  for(int i=0;i<*(signed char*)(self+0x1a);i++) {
   unsigned id=*(unsigned short*)(self+0x10+i*2);
   if(!id) Text_AppendFormattedIntegerAndStringFragment(out,i,empty);
   else {
    unsigned* record=(unsigned*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)manager,(short)id);
    if(!record) continue;
    Text_AppendFormattedIntegerAndStringFragment(out,i,(const char*)record[0]);
   }
   if(i!=*(signed char*)(self+0x1a)-1) Text_AppendFormatString(out,separator);
  }
 }
 TextMarkup_AppendPaletteTag(out,15);
 const char* footer=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,(void*)33);
 int width=TextLayout_ComputeWidthWithGlyphSpacing(footer,0);
 Text_AppendFormattedXYPair(out,(176-width)>>1,5);
 Text_AppendFormatString(out,footer);
 TextMarkup_AppendLineTag(out,17);
}
