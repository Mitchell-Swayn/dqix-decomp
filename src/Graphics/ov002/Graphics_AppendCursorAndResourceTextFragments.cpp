#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" void* LookupGlobalResourceByKey(unsigned);
// Original: arm9/ov002 @ 0x0216186C; symbol: func_ov002_0216186c; size: 0xB4.
extern "C" void Graphics_AppendCursorAndResourceTextFragments(unsigned char* self,char* out,int styled) {
 if(out) {
  int cursor=*(short*)(self+0x1c14);
  if(styled) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(out,cursor);
  const char* text=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)0x23f0);
  AppendFormattedNumberAndText(out,text,16);
  Text_AppendFormattedIntegerAndStringFragment(out,0,(const char*)LookupGlobalResourceByKey(0x1b));
  AppendFormatText(out,*(const char**)(self+0x1bdc));
  Text_AppendFormattedIntegerAndStringFragment(out,1,(const char*)LookupGlobalResourceByKey(0x1c));
 }
}
