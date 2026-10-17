#include <globaldefs.h>
ARM
extern "C" { int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*); int AppendFiveFormattedArguments(char*,int,int,int,int,int); int TextMarkup_AppendCursorTag(char*,int); int AppendFormatText(char*,const char*); void* ResolveIndexedRecordAndReturnSecondWord(void*,void*); extern char data_ov003_0217fe7f[]; }
// Original: arm9/ov003 @ 0x0215BE70; symbol: func_ov003_0215be70; size: 0xA8.
extern "C" void Graphics_AppendTwoIndexedLabelsWithCursor(unsigned char* object,char* text,int prefix) {
 if(text) {
  int cursor=*(signed char*)(object+0x586);
  if(prefix) AppendFiveFormattedArguments(text,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(text,cursor);
  for(int i=0;i<2;++i) {
   const char* label=(const char*)ResolveIndexedRecordAndReturnSecondWord(object+0x64,(void*)(int)(short)(i+20));
   Text_AppendFormattedIntegerAndStringFragment(text,i,label);
   if(i!=1) AppendFormatText(text,data_ov003_0217fe7f);
  }
 }
}
