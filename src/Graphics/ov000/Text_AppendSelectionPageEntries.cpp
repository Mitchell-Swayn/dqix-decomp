#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" void Selection_ComputeBoundedPageEntryRange(void*,int*,int*);
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" void String_ReplaceBracketedNamesByRowColumnTable(const signed char*,signed char*,int,unsigned,unsigned,int);
extern "C" void* GetIndexedFieldA4(void*,int);
extern "C" int IsStateAt118EqualTwo(void*);
extern "C" int TestIndexedFlagBit(void*,int);
// Original: arm9/ov000 @ 0x0217936C; symbol: func_ov000_0217936c; size: 0x160.
extern "C" void Text_AppendSelectionPageEntries(char* self,char* records,char* out) {
 if(!records||!out)return;
 int first,last;
 Selection_ComputeBoundedPageEntryRange(self+0x1dc,&first,&last);
 short begin=(short)first;
 short end=(short)last;
 short selected=*(short*)(records+0x1e);
 if(IsStateAt118EqualTwo(self))AppendFiveFormattedArguments(out,selected-begin,8,5,5,5);
 TextMarkup_AppendCursorTag(out,selected-begin);
 for(short i=begin;i<end;i++) {
  char* record=(char*)GetIndexedFieldA4(records,i);
  if(record) {
   int color=3;
   if(TestIndexedFlagBit(records,i))color=15;
   Text_AppendFormattedIntegerFragmentAt020EFF74(out,color);
   char expanded[128]; char formatted[128];
   __clear(expanded,128); __clear(formatted,128);
   String_ReplaceBracketedNamesByRowColumnTable(*(signed char**)record,(signed char*)expanded,1,0,0,0);
   Text_FormatAndConditionallyUppercaseOutput(expanded,formatted,0);
   Text_AppendFormattedIntegerAndStringFragment(out,i-begin,expanded);
   if(i!=end-1)AppendFormatText(out,(char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,0));
  }
 }
}
