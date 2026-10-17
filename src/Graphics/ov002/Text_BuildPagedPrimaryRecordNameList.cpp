#include <globaldefs.h>
ARM
struct GameState;struct Entry {unsigned pad;const char* name;char gap[0x10];short key;};
extern "C" int sprintf(char*,const char*,...);
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*);
extern "C" void SetOneOfSixteenWordFieldsAtOffset8B0(unsigned*,int,unsigned);
extern "C" void Selection_ComputeBoundedPageEntryRange(void*,int*,int*);
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
extern "C" int ReadSignedByteValueForNonnegativeHalfwordKey(char*,int);
extern "C" Entry* FindSerializedPrimaryRecordByKey(void*,int);
extern "C" void Util_SetRecordProgressFlags(void*,int,int,int);
extern "C" char data_ov002_0216d270[];
struct Page {char pad[0x54];int selection,count;char gap[12];int current;};
// Original: arm9/ov002 @ 0x0215D950; symbol: func_ov002_0215d950; size: 0x190.
extern "C" void Text_BuildPagedPrimaryRecordNameList(char* p,char* out,int formatted) {
 char name[256]; char value[64]; int start,end;
 if(out) {
  int cursor=*(short*)(p+0x1be8)&7;
  if(formatted)AppendFiveFormattedArguments(out,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(out,cursor);
  char* list=(char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv())+0xe04;
  unsigned owner=ReadWordFieldAtOffset1C();
  Page* page=(Page*)(p+0xec8);
  int row; int i;
  int pageCount=page->count;
  int current=page->current;
  Selection_ComputeBoundedPageEntryRange(&page->selection,&start,&end);
  row=0;
  for(i=start;i<end;++i) {
   ClearOwnerBuffersAndResetSignedByteSentinels((signed char*)owner);
   SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)owner,0,row);
   Entry* entry=FindSerializedPrimaryRecordByKey(p+0x7ec,*(short*)(list+12+i*2));
   if(entry) {
    __clear(name,256);
    Text_FormatAndConditionallyUppercaseOutput(entry->name,name,0);
    Text_AppendFormattedIntegerAndStringFragment(out,row,name);
    __clear(value,64);
    sprintf(value,data_ov002_0216d270,ReadSignedByteValueForNonnegativeHalfwordKey(list,entry->key));
    AppendFormatText(out,value);
    if(i!=end-1)AppendFormatText(out,*(char**)(p+0x1bdc));
   }
   ++row;
  }
  if(pageCount>1)Util_SetRecordProgressFlags(p,10,current,pageCount);
 }
}
