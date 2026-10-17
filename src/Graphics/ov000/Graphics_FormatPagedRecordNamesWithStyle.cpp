#include <globaldefs.h>
ARM
extern "C" void Selection_ComputeBoundedPageEntryRange(char*,int*,int*);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" int IsStateAt118EqualTwo(char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" char* GameState_GetIndexedWordIfValid(char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFormatText(char*,const char*);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE91(char*,int);
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
extern "C" void __clear(void*,unsigned);
extern "C" char data_ov000_02184069[];
struct Kind{unsigned pad[2];unsigned kind:4;unsigned rest:28;};
// Original: arm9/ov000 @ 0x0217979C; symbol: func_ov000_0217979c; size: 0x190.
extern "C" void Graphics_FormatPagedRecordNamesWithStyle(char* self,char* list,char* out){
 if(!list || !out)return;
 int begin,end;Selection_ComputeBoundedPageEntryRange(self+0x1dc,&begin,&end);
 signed char last,cursor,first;
 first=(signed char)begin;last=(signed char)end;
 cursor=*(signed char*)(list+0x22);
 const char* prefix=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,(void*)19);
 const char* separator=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,0);
 if(IsStateAt118EqualTwo(self))AppendFiveFormattedArguments(out,cursor-first,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor-first);
 for(signed char i=first;i<last;i++){
  char* entry=GameState_GetIndexedWordIfValid(list,i);
  if(!entry)Text_AppendFormattedIntegerAndStringFragment(out,i-first,data_ov000_02184069);
  else{
   char styled[128];__clear(styled,128);
   int regular=((Kind*)entry)->kind<=7;
   if(regular){AppendFormatText(styled,prefix);Text_AppendFormattedIntegerFragmentAt020EFE91(styled,3);}
   else Text_AppendFormattedIntegerFragmentAt020EFE91(styled,8);
   char name[256];__clear(name,256);
   Text_FormatAndConditionallyUppercaseOutput(*(const char**)(entry+4),name,0);
   AppendFormatText(styled,name);
   Text_AppendFormattedIntegerAndStringFragment(out,i-first,styled);
   if(i!=last-1)AppendFormatText(out,separator);
  }
 }
}
