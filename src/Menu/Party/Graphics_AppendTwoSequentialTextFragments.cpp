#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
// Original: arm9/ov002 @ 0x0215DD0C; symbol: func_ov002_0215dd0c; size: 0xB0.
extern "C" void Graphics_AppendTwoSequentialTextFragments(unsigned char* p,char* out,int header){
 if(!out)return;
 int cursor=*(short*)(p+0x1bf2);
 short index=0x79f;
 if(header)TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 for(int i=0;i<2;i++){
 const char* text=(const char*)ResourceStringTable_GetTextByKey(p+0x20,(void*)index++);
 Text_AppendFormattedIntegerAndStringFragment(out,i,text);
 if(i!=1)Text_AppendFormatString(out,*(const char**)(p+0x1bdc));
 }
}
