#include <globaldefs.h>
ARM
extern "C" char data_ov003_0217ff3e[];
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
// Original: arm9/ov003 @ 0x0215E13C; symbol: func_ov003_0215e13c; size: 0xB0.
extern "C" void Graphics_AppendCursorAndIndexedTextList(unsigned char* self,char* out,int styled) {
 if(out) {
  int cursor=*(signed char*)(self+0x3c1);
  if(styled) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(out,cursor);
  for(int i=0;i<self[0x3c0];i++) {
   const char* text=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0x64,(void*)(unsigned)(self+i)[0x3bd]);
   Text_AppendFormattedIntegerAndStringFragment(out,i,text);
   if(i!=self[0x3c0]-1) AppendFormatText(out,data_ov003_0217ff3e);
  }
 }
}
