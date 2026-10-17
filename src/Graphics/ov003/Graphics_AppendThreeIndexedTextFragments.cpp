#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
// Original: arm9/ov003 @ 0x02169A84; symbol: func_ov003_02169a84; size: 0xAC.
extern "C" void Graphics_AppendThreeIndexedTextFragments(unsigned char* p,char* out,int header){
 if(!out)return;
 int cursor=*(signed char*)(p+0x4ed);
 if(header)AppendFiveFormattedArguments(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 for(int i=0;i<3;i++){
 const char* text=(const char*)ResolveIndexedRecordAndReturnSecondWord(p+0x64,(void*)(short)i);
 Text_AppendFormattedIntegerAndStringFragment(out,i,text);
 if(i!=2)AppendFormatText(out,(const char*)ResolveIndexedRecordAndReturnSecondWord(p+0x64,(void*)100));
 }
}
