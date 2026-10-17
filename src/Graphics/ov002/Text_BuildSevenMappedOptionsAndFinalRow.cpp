#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void __clear(void*,unsigned);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormattedFiveIntegerFragment(char*,int,int,int,int,int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
extern "C" int AppendFormattedPair_Main02041A90(char*,int,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendLineTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" unsigned Text_AppendCenteredTextUsingComputedWidth(char*,const char*,int,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
struct Table8 {int values[8];};struct Table7 {int values[7];};
extern "C" const Table8 data_ov002_0216caa4;
extern "C" const Table7 data_ov002_0216ca88;
// Original: arm9/ov002 @ 0x021607CC; symbol: func_ov002_021607cc; size: 0x208.
extern "C" void Text_BuildSevenMappedOptionsAndFinalRow(char* p,char* out,int formatted) {
 if(!out)return;
 _ZN9GameState11GetInstanceEv();
 int selected=*(short*)(p+0x1c0a);
 Table8 positions=data_ov002_0216caa4;
 if(formatted)AppendFiveFormattedArguments(out,selected,8,5,5,5);
 TextMarkup_AppendCursorTag(out,selected);
 Text_AppendFormattedFiveIntegerFragment(out,100,2,2,2,2);
 const char* title=(const char*)ResolveIndexedRecordAndReturnSecondWord(p+32,(void*)0x1194);
 int width=TextLayout_ComputeWidthWithGlyphSpacing(title,0);
 Text_AppendFormattedIntegerFragmentAt020EFE78(out,(152-width)>>1);
 AppendFormatText(out,title);
 TextMarkup_AppendLineTag(out,17);
 Table7 mapping=data_ov002_0216ca88;
 char line[64];
 int key; int i;
 for(i=0;i<7;i++) {
  key=*(signed char*)(p+0x1c7c+mapping.values[i]);
  if(key<0)key=0x119d;else key+=0x119d;
  __clear(line,64);
  AppendFormattedPair_Main02041A90(out,43,positions.values[i]);
  if(key!=0x119d)AppendFormatText(line,(const char*)ResolveIndexedRecordAndReturnSecondWord(p+32,(void*)(int)(short)key));
  else Text_AppendCenteredTextUsingComputedWidth(line,(const char*)ResolveIndexedRecordAndReturnSecondWord(p+32,(void*)(int)(short)key),100,0);
  Text_AppendFormattedIntegerAndStringFragment(out,i,line);
 }
 Text_AppendFormattedFiveIntegerFragment(out,0,2,2,2,2);
 TextMarkup_AppendLineTag(out,162);
 AppendFormattedPair_Main02041A90(out,43,positions.values[i]);
 const char* finalText=(const char*)ResolveIndexedRecordAndReturnSecondWord(p+32,(void*)0x11fa);
 Text_AppendFormattedIntegerAndStringFragment(out,i,finalText);
}
