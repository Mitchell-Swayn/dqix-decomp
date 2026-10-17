#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int IsStateAt118EqualTwo(char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" char* GameState_GetIndexList(void*);
extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" void __clear(void*,unsigned);
extern "C" int ClassifyRatioAtThresholds(char*);
extern "C" int AppendTextByType(char*,unsigned);
extern "C" void Object_CopyTextFromSelectedFortyByteEntry(unsigned char*,unsigned);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" int AppendFormatText(char*,const char*);
extern "C" void* LookupGlobalResourceByKey(unsigned);
// Original: arm9/ov000 @ 0x021777E4; symbol: func_ov000_021777e4; size: 0x1D0.
extern "C" void Graphics_FormatAvailablePartyMemberChoices(char* self,char* out){
 if(!out)return;
 void* state=_ZN9GameState11GetInstanceEv();
 int cursor=*(signed char*)(self+0x1d6b);
 char* record;int count=0;
 unsigned char i;int kind,index;
 if(IsStateAt118EqualTwo(self))AppendFiveFormattedArguments(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 char* list=GameState_GetIndexList(state);
 char* records=self+0x158; i=0;records+=0x800;
 for(;i<*(unsigned char*)(list+0xf7c);i++){
  record=records+*(signed char*)(self+0x6c+i)*0x448;
  index=*(int*)(record+0x4c);
  int valid;
  if(index>=0 && index<=3)valid=1;else valid=0;
  if(!valid)continue;
  if(*(unsigned char*)(record+0x24)&2)continue;
  char* object=_ZN9GameState21GetPartyMemberByIndexEi(state,index);if(!object)return;
  unsigned char* data=ReadWordFieldAtOffset150(object);
  char buffer[128];__clear(buffer,128);
  kind=(signed char)*(int*)(data+0x94c);
  AppendTextByType(out,ClassifyRatioAtThresholds(record));
  Object_CopyTextFromSelectedFortyByteEntry((unsigned char*)record+0x68,(unsigned)buffer);
  Text_AppendFormattedIntegerAndStringFragment(out,count,buffer);
  Text_AppendFormattedIntegerFragmentAt020EFE78(out,78);
  AppendTextByType(out,0);
  const char* name=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,(void*)(short)(kind+0x753e));
  AppendFormatText(out,name);
  const char* separator=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,0);
  AppendFormatText(out,separator);
  *(unsigned char*)(self+0x1d74+count)=index;
  count++;
 }
 *(unsigned char*)(self+0x1d74+count)=4;
 const char* text=(const char*)LookupGlobalResourceByKey(26);
 Text_AppendFormattedIntegerAndStringFragment(out,count,text);
}
