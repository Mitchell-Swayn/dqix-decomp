#include <globaldefs.h>
ARM
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int TextMarkup_AppendSizeTag(char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
// Original: arm9/ov013 @ 0x02185BE0; symbol: func_ov013_02185be0; size: 0xE0.
// Appends cursor markup and two size-tagged choice labels, separated by record zero.
extern "C" void AppendTwoChoiceLabels(char* p,char* out){
 if(*(int*)(p+0x648)==2)TextMarkup_AppendFrameTag(out,*(int*)(p+0x660),9,3,6,2);
 TextMarkup_AppendCursorTag(out,*(int*)(p+0x660));
 for(int i=0;i<2;i++){
 char text[32]={0};TextMarkup_AppendSizeTag(text,12);
 Text_AppendFormatString(text,(const char*)ResourceStringTable_GetTextByKey(p+0x620,(void*)(int)(short)(i+10)));
 Text_AppendFormattedIntegerAndStringFragment(out,i,text);
 if(i<1)Text_AppendFormatString(out,(const char*)ResourceStringTable_GetTextByKey(p+0x620,0));
 }
}
