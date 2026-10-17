#include <globaldefs.h>
ARM
#pragma opt_arithtransformation off
#pragma opt_common_subs off
struct GameState; struct Output; struct Record;
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*);
extern "C" void SetOneOfSixteenWordFieldsAtOffset8B0(unsigned*,int,unsigned);
extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,void*,void*,int,int,unsigned);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" void* ClearMemoryRange12_Main020E46C4(void*);
extern "C" void BuildNameDescriptorAndLastLetterState(Output*,unsigned char*,int);
extern "C" void Record_CopySelectedTextAndNumericFields(const Record*,Record*,unsigned);
extern "C" int Object_CountMatchesAtOffset1D1C(unsigned char*,unsigned);
extern "C" int IsStateAt118EqualTwo(void*);
extern "C" void String_FormatAndTrimSuffix(void*,char*);
extern "C" char data_ov000_02184060[];
// Original: arm9/ov000 @ 0x02178938; symbol: func_ov000_02178938; size: 0x270.
extern "C" void Graphics_AppendGroupedMemberNameText(char* self,char* view,int total,char* out) {
 char text[128],nameA[128],nameB[128]; unsigned desc[3],fallback[3];
 int previous; int had; int selected; int cursor; int i; int decorated;
 if(!out) return;
 previous=-1;
 selected=0;had=0;
 cursor=*(signed char*)(view+0x1d);
 for(i=0;i<total;i++) {
  unsigned value=*(unsigned*)(self+0x1d1c+i*4);
  if(previous!=value) {
   previous=value;
   int n=Object_CountMatchesAtOffset1D1C((unsigned char*)self,value);
   if(i<=cursor && cursor<i+n) selected=i;
  }
 }
 decorated=IsStateAt118EqualTwo(self);
 signed char* display=(signed char*)ReadWordFieldAtOffset1C();
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 const char* separator=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,0);
 void* format=ResolveIndexedRecordAndReturnSecondWord(self+0xb8,(void*)0x754f);
 previous=-1;
 if(decorated) AppendFiveFormattedArguments(out,selected,8,5,5,5);
 TextMarkup_AppendCursorTag(out,selected);
 for(i=0;i<total;i++) {
  unsigned value=*(unsigned*)(self+0x1d1c+i*4);
  if(previous!=value) {
   previous=value;
   int n=Object_CountMatchesAtOffset1D1C((unsigned char*)self,value);
   if(!n) continue;
   if(had) AppendFormatText(out,separator);
   __clear(text,128);
   int chosen=i;
   if(i<=cursor && cursor<i+n) chosen=cursor;
   ClearOwnerBuffersAndResetSignedByteSentinels(display);
   ClearMemoryRange12_Main020E46C4(desc);
   unsigned char* member=GameState_FindIndexedObjectWithFlag400(game,*(unsigned*)(self+0x1d3c+chosen*4));
   __clear(nameA,128);__clear(nameB,128);
   if(member) {
    BuildNameDescriptorAndLastLetterState((Output*)desc,member,1);
    BuildNameDescriptorAndLastLetterState((Output*)fallback,member,0);
    String_FormatAndTrimSuffix((void*)desc[0],nameA);
    String_FormatAndTrimSuffix((void*)desc[1],nameB);
    desc[0]=(unsigned)nameA;desc[1]=(unsigned)nameB;
    Record_CopySelectedTextAndNumericFields((Record*)fallback,(Record*)desc,2);
    desc[2]&=~0x80000000;
   }
   *(unsigned**)(display+0x20)=desc;
   SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)display,0,n);
   ProcessSixStagesUsingSharedWordScratchBuffer(display,10,format,text,256,0,0);
   Text_AppendFormattedIntegerAndStringFragment(out,i,text);
   had=1;
  }
 }
 AppendFormatText(out,data_ov000_02184060);
}
