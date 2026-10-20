#include <globaldefs.h>
ARM
extern "C" {
int sprintf(char*,const char*,...);
void __clear(void*,unsigned);
int TextMarkup_AppendXPositionTag(char*,int);
int TextMarkup_AppendYTag(char*,int);
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
int TextMarkup_AppendLineTag(char*,int);
int Text_AppendFormattedFourIntegerFragment(char*,int,int,int,int);
int TextMarkup_AppendPaletteTag(char*,int);
int TextMarkup_AppendCursorTag(char*,int);
int AppendFormattedNumberAndText(char*,const char*,int);
int Text_AppendFormatString(char*,const char*);
int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
void* ResourceStringTable_GetTextByKey(void*,void*);
}
#define TEXT(n) ((const char*)ResourceStringTable_GetTextByKey(self+0x620,(void*)(n)))
// Original: arm9/ov013 @ 0x02185424; symbol: func_ov013_02185424; size: 0x350.
extern "C" void Graphics_FormatFiveRowSelectionText(unsigned char* self,char* output) {
char buffer[256]; __clear(buffer,256);
const char* title=TEXT(0x2718);
TextMarkup_AppendXPositionTag(buffer,(240-TextLayout_ComputeWidthWithGlyphSpacing(title,0))>>1);
Text_AppendFormatString(buffer,title);
AppendFormattedNumberAndText(output,buffer,16);
if(*(int*)(self+0x648)==2) TextMarkup_AppendFrameTag(output,*(int*)(self+0x65c),8,3,6,2);
TextMarkup_AppendCursorTag(output,*(int*)(self+0x65c));
for(unsigned char i=0;i<5;i++) {
if(!(self+i)[0x69c]) TextMarkup_AppendPaletteTag(output,15);
else TextMarkup_AppendPaletteTag(output,3);
const char* text=TEXT((short)((self+i)[0x6a9]+100));
sprintf(buffer,TEXT(0x2711),i,text);
Text_AppendFormatString(output,buffer);
if(i!=4) sprintf(buffer,TEXT(0));
Text_AppendFormatString(output,buffer);
}
TextMarkup_AppendYTag(output,21);
int y;
for(int i=0;i<5;i++) {
y=13*i;
int first=*(int*)(self+i*4+0x674);
int second=*(int*)(self+i*4+0x688);
if((self+i)[0x69c]==1) {
sprintf(buffer,TEXT(0x2712),y+22,second,first);
} else if(i==*(int*)(self+0x65c)) {
if(!second) sprintf(buffer,TEXT(0x2714),y+22,10,second,11,first);
else sprintf(buffer,TEXT(0x2713),y+22,10,second,11,first,first+second);
} else {
if(!second) sprintf(buffer,TEXT(0x2716),y+22,second,first);
else sprintf(buffer,TEXT(0x2715),y+22,second,first,first+second);
}
Text_AppendFormatString(output,buffer);
if(i!=4) Text_AppendFormatString(output,TEXT(0));
}
TextMarkup_AppendLineTag(output,87);
Text_AppendFormattedFourIntegerFragment(output,0x7fff,90,16,87);
sprintf(buffer,TEXT(0x2717),*(int*)(self+0x66c));
Text_AppendFormatString(output,buffer);
}
