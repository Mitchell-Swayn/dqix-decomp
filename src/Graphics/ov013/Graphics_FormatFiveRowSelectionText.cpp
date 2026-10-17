#include <globaldefs.h>
ARM
extern "C" {
int sprintf(char*,const char*,...);
void __clear(void*,unsigned);
int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
int TextMarkup_AppendYTag(char*,int);
int AppendFiveFormattedArguments(char*,int,int,int,int,int);
int TextMarkup_AppendLineTag(char*,int);
int Text_AppendFormattedFourIntegerFragment(char*,int,int,int,int);
int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
int TextMarkup_AppendCursorTag(char*,int);
int AppendFormattedNumberAndText(char*,const char*,int);
int AppendFormatText(char*,const char*);
int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
}
#define TEXT(n) ((const char*)ResolveIndexedRecordAndReturnSecondWord(self+0x620,(void*)(n)))
// Original: arm9/ov013 @ 0x02185424; symbol: func_ov013_02185424; size: 0x350.
extern "C" void Graphics_FormatFiveRowSelectionText(unsigned char* self,char* output) {
char buffer[256]; __clear(buffer,256);
const char* title=TEXT(0x2718);
Text_AppendFormattedIntegerFragmentAt020EFE78(buffer,(240-TextLayout_ComputeWidthWithGlyphSpacing(title,0))>>1);
AppendFormatText(buffer,title);
AppendFormattedNumberAndText(output,buffer,16);
if(*(int*)(self+0x648)==2) AppendFiveFormattedArguments(output,*(int*)(self+0x65c),8,3,6,2);
TextMarkup_AppendCursorTag(output,*(int*)(self+0x65c));
for(unsigned char i=0;i<5;i++) {
if(!(self+i)[0x69c]) Text_AppendFormattedIntegerFragmentAt020EFF74(output,15);
else Text_AppendFormattedIntegerFragmentAt020EFF74(output,3);
const char* text=TEXT((short)((self+i)[0x6a9]+100));
sprintf(buffer,TEXT(0x2711),i,text);
AppendFormatText(output,buffer);
if(i!=4) sprintf(buffer,TEXT(0));
AppendFormatText(output,buffer);
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
AppendFormatText(output,buffer);
if(i!=4) AppendFormatText(output,TEXT(0));
}
TextMarkup_AppendLineTag(output,87);
Text_AppendFormattedFourIntegerFragment(output,0x7fff,90,16,87);
sprintf(buffer,TEXT(0x2717),*(int*)(self+0x66c));
AppendFormatText(output,buffer);
}
