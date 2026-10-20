#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void __clear(void*,unsigned);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormattedFiveIntegerFragment(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
extern "C" int Text_AppendFormattedXYPair(char*,int,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendLineTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" unsigned Text_AppendCenteredTextUsingComputedWidth(char*,const char*,int,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
struct Table8 {int values[8];};struct Table7 {int values[7];};
// Original data: arm9/ov002 @ 0x216caa4; symbol: data_ov002_0216caa4.
// Text placement parameters for eight menu fields; Text_BuildSevenMappedOptionsAndFinalRow selects word entries for text-control 0x2b.
// Initial values: hex 1b000000330000004b00000063000000730000008300000093000000a7000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" const Table8 TextBuildSevenMappedOptionsAndFinalRow_TextPlacementParametersForEightMenuFields;
// Original data: arm9/ov002 @ 0x216ca88; symbol: data_ov002_0216ca88.
// Menu logical slot to storage slot mapping; Text_BuildSevenMappedOptionsAndFinalRow iterates seven word entries.
// Initial values: hex 00000000020000000100000003000000040000000500000006000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" const Table7 TextBuildSevenMappedOptionsAndFinalRow_MenuLogicalSlotToStorageSlotMapping;
// Original: arm9/ov002 @ 0x021607CC; symbol: func_ov002_021607cc; size: 0x208.
extern "C" void Text_BuildSevenMappedOptionsAndFinalRow(char* p,char* out,int formatted) {
 if(!out)return;
 _ZN9GameState11GetInstanceEv();
 int selected=*(short*)(p+0x1c0a);
 Table8 positions=TextBuildSevenMappedOptionsAndFinalRow_TextPlacementParametersForEightMenuFields;
 if(formatted)TextMarkup_AppendFrameTag(out,selected,8,5,5,5);
 TextMarkup_AppendCursorTag(out,selected);
 Text_AppendFormattedFiveIntegerFragment(out,100,2,2,2,2);
 const char* title=(const char*)ResourceStringTable_GetTextByKey(p+32,(void*)0x1194);
 int width=TextLayout_ComputeWidthWithGlyphSpacing(title,0);
 TextMarkup_AppendXPositionTag(out,(152-width)>>1);
 Text_AppendFormatString(out,title);
 TextMarkup_AppendLineTag(out,17);
 Table7 mapping=TextBuildSevenMappedOptionsAndFinalRow_MenuLogicalSlotToStorageSlotMapping;
 char line[64];
 int key; int i;
 for(i=0;i<7;i++) {
  key=*(signed char*)(p+0x1c7c+mapping.values[i]);
  if(key<0)key=0x119d;else key+=0x119d;
  __clear(line,64);
  Text_AppendFormattedXYPair(out,43,positions.values[i]);
  if(key!=0x119d)Text_AppendFormatString(line,(const char*)ResourceStringTable_GetTextByKey(p+32,(void*)(int)(short)key));
  else Text_AppendCenteredTextUsingComputedWidth(line,(const char*)ResourceStringTable_GetTextByKey(p+32,(void*)(int)(short)key),100,0);
  Text_AppendFormattedIntegerAndStringFragment(out,i,line);
 }
 Text_AppendFormattedFiveIntegerFragment(out,0,2,2,2,2);
 TextMarkup_AppendLineTag(out,162);
 Text_AppendFormattedXYPair(out,43,positions.values[i]);
 const char* finalText=(const char*)ResourceStringTable_GetTextByKey(p+32,(void*)0x11fa);
 Text_AppendFormattedIntegerAndStringFragment(out,i,finalText);
}
