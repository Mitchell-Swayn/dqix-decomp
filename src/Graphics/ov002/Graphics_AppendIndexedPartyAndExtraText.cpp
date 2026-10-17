#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" int Graphics_SelectObjectRatioColor(void*,int,int,int,int);
extern "C" void GameState_BuildOutputWordListFromIndexedData(void*,int*);
// Original: arm9/ov002 @ 0x0215DB8C; symbol: func_ov002_0215db8c; size: 0x180.
extern "C" void Graphics_AppendIndexedPartyAndExtraText(char* p,char* out,int decorated) {
 int indices[7]; char* member; void* state;
 int cursor; int textId; int memberIndex; int count; int i;
 if(!out) return;
 state=_ZN9GameState11GetInstanceEv();
 cursor=*(short*)(p+0x1bf0);
 textId=0x76d;
 GameState_BuildOutputWordListFromIndexedData(p,indices);
 if(decorated) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 AppendFormattedNumberAndText(out,(const char*)ResolveIndexedRecordAndReturnSecondWord(p+0x20,(void*)0x76c),16);
 count=*(int*)(p+0x1c38)+1;
 for(i=0;i<count;i++) {
  memberIndex=indices[i];
  int valid;
  if(memberIndex>=0 && memberIndex<=3) valid=1; else valid=0;
  if(valid) {
   member=(char*)_ZN9GameState21GetPartyMemberByIndexEi(state,memberIndex);
   if(member) {
    Text_AppendFormattedIntegerFragmentAt020EFF74(out,Graphics_SelectObjectRatioColor(p,memberIndex,0,1,1));
    Text_AppendFormattedIntegerAndStringFragment(out,i,*(const char**)(member+0x134));
    Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
   }
  } else {
   int id=textId; textId=(short)(textId+1);
   Text_AppendFormattedIntegerAndStringFragment(out,i,(const char*)ResolveIndexedRecordAndReturnSecondWord(p+0x20,(void*)id));
  }
  if(i!=count-1) AppendFormatText(out,*(const char**)(p+0x1bdc));
 }
}
