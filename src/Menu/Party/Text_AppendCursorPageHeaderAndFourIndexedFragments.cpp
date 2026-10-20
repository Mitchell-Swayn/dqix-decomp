#include <globaldefs.h>
ARM
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void __clear(void*,unsigned);
extern "C" void Graphics_AppendCenteredFormattedText(char**,const char*,unsigned);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Text_AppendFormatString(char*,const char*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov002 @ 0x0215CD98; symbol: Text_AppendCursorPageHeaderAndFourIndexedFragments; size: 0xFC.
extern "C" void Text_AppendCursorPageHeaderAndFourIndexedFragments(char* self,char* output,int format){if(!output)return;short key=1200;int cursor=S(self,0x1bea);if(format)TextMarkup_AppendFrameTag(output,cursor,8,5,5,5);TextMarkup_AppendCursorTag(output,cursor);const char* first=(const char*)ResourceStringTable_GetTextByKey(self+32,(void*)key++);char buffer[128];__clear(buffer,128);char* write=buffer;Graphics_AppendCenteredFormattedText(&write,first,0);AppendFormattedNumberAndText(output,buffer,16);for(int i=0;i<4;++i){const char* text=(const char*)ResourceStringTable_GetTextByKey(self+32,(void*)key++);Text_AppendFormattedIntegerAndStringFragment(output,i,text);if(i!=3)Text_AppendFormatString(output,P(self,0x1bdc));}}