#include <globaldefs.h>
ARM
extern "C" {
void Memory_CopyConstantBlock16(void*,void*);
bool BattleMenu_HasTouchSelectionChanged(char*);
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
int TextMarkup_AppendCursorTag(char*,int);
int Text_AppendFormatString(char*,const char*);
void* ResourceStringTable_GetTextByKey(void*,void*);
void* Text_LookupStandardString(unsigned);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern short BattleMenuAppendPartyCommandOptions_UnknownRoleInitializedBytes[];
}
// Original: arm9/ov000 @ 0x0217737C; symbol: BattleMenu_AppendPartyCommandOptions; size: 0xD8.
// Appends valid resource fragments from four configured entries with a cursor tag and separators.
extern "C" void BattleMenu_AppendPartyCommandOptions(char* owner,char* output)
{
 if(!output)return;
 int entries[4];
 Memory_CopyConstantBlock16(owner,entries);
 int cursor=((signed char*)owner)[0x1d69];
 int appended=0;
 if(BattleMenu_HasTouchSelectionChanged(owner))TextMarkup_AppendFrameTag(output,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(output,cursor);
 for(int i=0;i<4;i++){
  int entry=entries[i];
  if(entry<0)continue;
  if(appended)Text_AppendFormatString(output,(const char*)ResourceStringTable_GetTextByKey(owner+0xb8,0));
  const char* text=(const char*)Text_LookupStandardString(BattleMenuAppendPartyCommandOptions_UnknownRoleInitializedBytes[entry]);
  Text_AppendFormattedIntegerAndStringFragment(output,appended,text);
  appended++;
 }
}
