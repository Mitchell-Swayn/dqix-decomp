#include <globaldefs.h>
ARM
extern "C" void Selection_ComputeBoundedPageEntryRange(char*,int*,int*);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int BattleMenu_HasTouchSelectionChanged(char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" char* GameState_GetIndexedWordIfValid(char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int TextMarkup_AppendWidthTag(char*,int);
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
extern "C" void __clear(void*,unsigned);
// Original data: arm9/ov000 @ 0x02184069; symbol: data_ov000_02184069.
// Literal <W=0>; Graphics_FormatPagedRecordNamesWithStyle emits it for a missing item entry.
// Values (char[6]): "<W=0>" + NUL (6 bytes).
extern "C" char BattleMenu_EmptyItemWidthMarkup[];
struct Kind{unsigned pad[2];unsigned kind:4;unsigned rest:28;};
// Original: arm9/ov000 @ 0x0217979C; symbol: func_ov000_0217979c; size: 0x190.
extern "C" void Graphics_FormatPagedRecordNamesWithStyle(char* self,char* list,char* out){
 if(!list || !out)return;
 int begin,end;Selection_ComputeBoundedPageEntryRange(self+0x1dc,&begin,&end);
 signed char last,cursor,first;
 first=(signed char)begin;last=(signed char)end;
 cursor=*(signed char*)(list+0x22);
 const char* prefix=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,(void*)19);
 const char* separator=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,0);
 if(BattleMenu_HasTouchSelectionChanged(self))TextMarkup_AppendFrameTag(out,cursor-first,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor-first);
 for(signed char i=first;i<last;i++){
  char* entry=GameState_GetIndexedWordIfValid(list,i);
  if(!entry)Text_AppendFormattedIntegerAndStringFragment(out,i-first,BattleMenu_EmptyItemWidthMarkup);
  else{
   char styled[128];__clear(styled,128);
   int regular=((Kind*)entry)->kind<=7;
   if(regular){Text_AppendFormatString(styled,prefix);TextMarkup_AppendWidthTag(styled,3);}
   else TextMarkup_AppendWidthTag(styled,8);
   char name[256];__clear(name,256);
   Text_FormatAndConditionallyUppercaseOutput(*(const char**)(entry+4),name,0);
   Text_AppendFormatString(styled,name);
   Text_AppendFormattedIntegerAndStringFragment(out,i-first,styled);
   if(i!=last-1)Text_AppendFormatString(out,separator);
  }
 }
}
