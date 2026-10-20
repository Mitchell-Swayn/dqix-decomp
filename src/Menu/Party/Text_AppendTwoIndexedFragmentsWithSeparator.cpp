#include <globaldefs.h>
ARM
extern "C" {int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);int TextMarkup_AppendCursorTag(char*,int);int Text_AppendFormatString(char*,const char*);void* ResourceStringTable_GetTextByKey(void*,void*);}
// Original: arm9/ov002 @ 0x021610C4; symbol: func_ov002_021610c4; size: 0xB0.
extern "C" void Text_AppendTwoIndexedFragmentsWithSeparator(char* owner,char* output,int formatted){
if(!output)return;
int cursor=*(short*)(owner+0x1c12);short key=0x26ad;
if(formatted)TextMarkup_AppendFrameTag(output,cursor,8,5,5,5);
TextMarkup_AppendCursorTag(output,cursor);
for(int i=0;i<2;i++){
const char* fragment=(const char*)ResourceStringTable_GetTextByKey(owner+0x20,(void*)key++);
Text_AppendFormattedIntegerAndStringFragment(output,i,fragment);
if(i!=1)Text_AppendFormatString(output,*(char**)(owner+0x1bdc));
}
}
