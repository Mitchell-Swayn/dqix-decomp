#include <globaldefs.h>
ARM
struct T;
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
extern "C" int AppendFormattedPair_Main02041A90(char*,int,int);
extern "C" int TextMarkup_AppendHTag(char*,int);
extern "C" int AppendFormattedPair_Main02041B34(char*,int,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int AppendFourFormattedArguments(char*,int,int,int,int);
extern "C" int Text_AppendFormattedFourIntegerFragment(char*,int,int,int,int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
extern "C" unsigned FindRecordValueByKeyOrZero(T*,int);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
extern "C" short data_ov012_0218af92[];
extern "C" char data_ov012_0218b305[];
struct SummaryWord { unsigned number:12,category:4,part:5,detail:4,pad:2,special:1,pad2:3,valid:1; };
// Original: arm9/ov012 @ 0x021894B4; symbol: func_ov012_021894b4; size: 0x408.
extern "C" void Graphics_AppendCenteredSummaryText(unsigned char* self,char* out,int init) {
if(out) {
int cursor=*(int*)(self+0x13d4);
if(init) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
TextMarkup_AppendCursorTag(out,cursor);
const char* text=(const char*)FindRecordValueByKeyOrZero((T*)(self+0x133c),1);
Text_AppendFormattedIntegerFragmentAt020EFE78(out,(224-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1);
AppendFormattedNumberAndText(out,text,16);
TextMarkup_AppendHTag(out,3);
Text_AppendFormattedIntegerAndStringFragment(out,0,(const char*)FindRecordValueByKeyOrZero((T*)(self+0x133c),2));
int line=1;
short* keys=data_ov012_0218af92;
for(;;) {
int tableKey=*keys;
if(tableKey<0) break;
AppendFormatText(out,*(const char**)(self+0x1378));
if(line==5) AppendFormattedPair_Main02041B34(out,3,3);
Text_AppendFormattedIntegerAndStringFragment(out,line,(const char*)FindRecordValueByKeyOrZero((T*)(self+0x133c),tableKey));
line++;keys++;
}
AppendFourFormattedArguments(out,0x7fff,2,0xdd,0x66);
Text_AppendFormattedFourIntegerFragment(out,0x7fff,0x58,0x10,0x66);
unsigned char* gs=(unsigned char*)_ZN9GameState11GetInstanceEv();
SummaryWord* summary=(SummaryWord*)(gs+0x569c);
ReadWordFieldAtOffset1C();
char longbuf[256];
char decorated[128];
char unused[32]={0};
AppendFormattedPair_Main02041A90(out,0x58+((0x88-TextLayout_ComputeWidthWithGlyphSpacing((char*)self+0x1440,0))>>1),0x16);
AppendFormatText(out,(char*)self+0x1440);
__clear(longbuf,256);
text=(const char*)FindRecordValueByKeyOrZero((T*)(self+0x133c),(short)(summary->category+0x13));
int width;
if(summary->valid) {
sprintf(longbuf,data_ov012_0218b305,summary->part,text,summary->number);
width=TextLayout_ComputeWidthWithGlyphSpacing(longbuf,0);
} else {
text=(const char*)FindRecordValueByKeyOrZero((T*)(self+0x133c),0x78);
int length=String_CountBytesUntilTerminator((const signed char*)text);
char truncated[64]={0};
memcpy(truncated,text+8,length-17);
width=TextLayout_ComputeWidthWithGlyphSpacing(truncated,0);
sprintf(longbuf,text);
}
AppendFormattedPair_Main02041A90(out,0x58+((0x88-width)>>1),0x26);
AppendFormatText(out,longbuf);
__clear(decorated,128);
Text_FormatAndConditionallyUppercaseOutput((char*)self+0x1400,decorated,0);
AppendFormattedPair_Main02041A90(out,0x58+((0x88-TextLayout_ComputeWidthWithGlyphSpacing(decorated,0))>>1),0x36);
AppendFormatText(out,decorated);
short key=0x6d;
if(summary->special) key=(short)(summary->detail+0x7530);
text=(const char*)FindRecordValueByKeyOrZero((T*)(self+0x133c),key);
AppendFormattedPair_Main02041A90(out,0x58+((0x88-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1),0x46);
AppendFormatText(out,text);
char* state=(char*)summary+8;
int highlight=0;
if(self[0x1371]==14 && self[0x1370]>=1 && self[0x1370]<=4) state=*(char**)(self+0x13d0);
if(!*state) {
text=(const char*)FindRecordValueByKeyOrZero((T*)(self+0x133c),0x12);
highlight=1;
} else text=(const char*)FindRecordValueByKeyOrZero((T*)(self+0x133c),0x13);
AppendFormattedPair_Main02041A90(out,0x58+((0x88-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1),0x56);
if(highlight) Text_AppendFormattedIntegerFragmentAt020EFF74(out,3);
AppendFormatText(out,text);
}
}
