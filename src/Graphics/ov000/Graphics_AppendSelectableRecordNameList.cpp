#include <globaldefs.h>
ARM
extern "C" int AppendFormattedPair_Main02041A90(char*,int,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendLineTag(char*,int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void* ReadGlobalAt02108E10();
extern "C" unsigned* TryTransformFirstOrSecondEmbeddedRecord(void*,int);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" int IsStateAt118EqualTwo(void*);
// Original: arm9/ov000 @ 0x0217A2DC; symbol: func_ov000_0217a2dc; size: 0x238.
extern "C" void Graphics_AppendSelectableRecordNameList(char* self,void*,char* out) {
 const char* empty=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,(void*)31);
 const char* separator=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,0);
 int cursor=*(signed char*)(self+0x1d6d);
 AppendFormatText(out,separator);
 if(*(unsigned char*)(self+0x1d81)) {
  if(IsStateAt118EqualTwo(self)) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
  void* manager=ReadGlobalAt02108E10();
  if(!manager) return;
  for(int i=0;i<*(signed char*)(self+0x1a);i++) {
   int color=3;
   if(i==cursor) color=5;
   Text_AppendFormattedIntegerFragmentAt020EFF74(out,color);
   unsigned id=*(unsigned short*)(self+0x10+i*2);
   if(!id) AppendFormatText(out,empty);
   else {
    unsigned* record=TryTransformFirstOrSecondEmbeddedRecord(manager,(short)id);
    if(!record) continue;
    AppendFormatText(out,(const char*)record[0]);
   }
   if(i!=*(signed char*)(self+0x1a)-1) AppendFormatText(out,separator);
  }
 } else {
  if(IsStateAt118EqualTwo(self)) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(out,cursor);
  void* manager=ReadGlobalAt02108E10();
  if(!manager) return;
  for(int i=0;i<*(signed char*)(self+0x1a);i++) {
   unsigned id=*(unsigned short*)(self+0x10+i*2);
   if(!id) Text_AppendFormattedIntegerAndStringFragment(out,i,empty);
   else {
    unsigned* record=TryTransformFirstOrSecondEmbeddedRecord(manager,(short)id);
    if(!record) continue;
    Text_AppendFormattedIntegerAndStringFragment(out,i,(const char*)record[0]);
   }
   if(i!=*(signed char*)(self+0x1a)-1) AppendFormatText(out,separator);
  }
 }
 Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
 const char* footer=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,(void*)33);
 int width=TextLayout_ComputeWidthWithGlyphSpacing(footer,0);
 AppendFormattedPair_Main02041A90(out,(176-width)>>1,5);
 AppendFormatText(out,footer);
 TextMarkup_AppendLineTag(out,17);
}
