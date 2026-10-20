#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
// Original: arm9/ov005 @ 0x02159A30; symbol: func_ov005_02159a30; size: 0x144.
extern "C" void Text_FormatIndexedListAndCenterLayout(char* self,char* out,int appendStyle) {
 if(!out)return;
 int cursor=*(signed char*)(self+0x3dde);
 if(appendStyle)TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 int count=4;int special=0;
 int selected=*(signed char*)(self+0x3dbb);
 if(selected>=0 && selected<8){--count;special=1;}
 char* records=self+0xdf8;
 const char* separator=(const char*)ResourceStringTable_GetTextByKey(records,(void*)100);
 int maxWidth=0;
 for(int i=0;i<count;++i) {
 short index=i;
 if(special) {index=index+1;if(i==0)index=4;}
 const char* text=(const char*)ResourceStringTable_GetTextByKey(records,(void*)index);
 int width=TextLayout_ComputeWidthWithGlyphSpacing(text,0);
 if(maxWidth<width)maxWidth=width;
 Text_AppendFormattedIntegerAndStringFragment(out,i,text);
 if(i!=count-1)Text_AppendFormatString(out,separator);
 }
 int width=(maxWidth+27)&~7;
 width=(width>>3)+((width>>3)&1);
 *(short*)(self+0xf84)=width;
 *(short*)(self+0xf86)=7;
 *(short*)(self+0xf88)=(32-width)>>1;
 *(short*)(self+0xf8a)=9;
}
