#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" int data_ov000_021834f8[];
// Original: arm9/ov000 @ 0x02176500; symbol: func_ov000_02176500; size: 0x134.
extern "C" void Text_AppendSixObjectRecordLabels(unsigned char* self,char* out,int prefix) {
 if(!out || !*(void**)(self+4)) return;
 unsigned char* obj=(unsigned char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),*(int*)(self+0x4c));
 if(!obj) return;
 int special=0;
 if(((unsigned int)*(unsigned char*)(*(unsigned char**)(obj+0x138)+0x3b)<<28)>>31) special=1;
 int cursor=*(signed char*)(self+0x1c);
 if(prefix) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 for(int i=0;i<6;i++) {
  int id=data_ov000_021834f8[i];
  if(!special && id==5) Text_AppendFormattedIntegerFragmentAt020EFF74(out,3);
  const char* text=(const char*)ResolveIndexedRecordAndReturnSecondWord(*(void**)(self+4),(void*)(int)(short)(id+0x7534));
  Text_AppendFormattedIntegerAndStringFragment(out,id,text);
  if(i==5) break;
  if(i&1) AppendFormatText(out,(const char*)ResolveIndexedRecordAndReturnSecondWord(*(void**)(self+4),0));
  else Text_AppendFormattedIntegerFragmentAt020EFE78(out,0x45);
  Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
 }
}
