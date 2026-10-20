#include <globaldefs.h>
ARM
struct T;
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
extern "C" int Text_AppendFormattedXYPair(char*,int,int);
extern "C" int TextMarkup_AppendHTag(char*,int);
extern "C" int TextMarkup_AppendWidthHeightTag(char*,int,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int AppendFourFormattedArguments(char*,int,int,int,int);
extern "C" int Text_AppendFormattedFourIntegerFragment(char*,int,int,int,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
// Original data: arm9/ov012 @ 0x218af92; symbol: data_ov012_0218af92.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 03000400050006000c00ffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
extern "C" short GraphicsAppendCenteredSummaryText_UnknownRoleInitializedBytes[];
extern "C" char Graphics_AppendCenteredSummaryText_FormatDSD[];
struct SummaryWord { unsigned number:12,category:4,part:5,detail:4,pad:2,special:1,pad2:3,valid:1; };
// Original: arm9/ov012 @ 0x021894B4; symbol: func_ov012_021894b4; size: 0x408.
extern "C" void Graphics_AppendCenteredSummaryText(unsigned char* self,char* out,int init) {
if(out) {
int cursor=*(int*)(self+0x13d4);
if(init) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
TextMarkup_AppendCursorTag(out,cursor);
const char* text=(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),1);
TextMarkup_AppendXPositionTag(out,(224-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1);
AppendFormattedNumberAndText(out,text,16);
TextMarkup_AppendHTag(out,3);
Text_AppendFormattedIntegerAndStringFragment(out,0,(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),2));
int line=1;
short* keys=GraphicsAppendCenteredSummaryText_UnknownRoleInitializedBytes;
for(;;) {
int tableKey=*keys;
if(tableKey<0) break;
Text_AppendFormatString(out,*(const char**)(self+0x1378));
if(line==5) TextMarkup_AppendWidthHeightTag(out,3,3);
Text_AppendFormattedIntegerAndStringFragment(out,line,(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),tableKey));
line++;keys++;
}
AppendFourFormattedArguments(out,0x7fff,2,0xdd,0x66);
Text_AppendFormattedFourIntegerFragment(out,0x7fff,0x58,0x10,0x66);
unsigned char* gs=(unsigned char*)_ZN9GameState11GetInstanceEv();
SummaryWord* summary=(SummaryWord*)(gs+0x569c);
TextContext_GetSharedInstance();
char longbuf[256];
char decorated[128];
char unused[32]={0};
Text_AppendFormattedXYPair(out,0x58+((0x88-TextLayout_ComputeWidthWithGlyphSpacing((char*)self+0x1440,0))>>1),0x16);
Text_AppendFormatString(out,(char*)self+0x1440);
__clear(longbuf,256);
text=(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),(short)(summary->category+0x13));
int width;
if(summary->valid) {
sprintf(longbuf,Graphics_AppendCenteredSummaryText_FormatDSD,summary->part,text,summary->number);
width=TextLayout_ComputeWidthWithGlyphSpacing(longbuf,0);
} else {
text=(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),0x78);
int length=String_CountBytesUntilTerminator((const signed char*)text);
char truncated[64]={0};
memcpy(truncated,text+8,length-17);
width=TextLayout_ComputeWidthWithGlyphSpacing(truncated,0);
sprintf(longbuf,text);
}
Text_AppendFormattedXYPair(out,0x58+((0x88-width)>>1),0x26);
Text_AppendFormatString(out,longbuf);
__clear(decorated,128);
Text_FormatAndConditionallyUppercaseOutput((char*)self+0x1400,decorated,0);
Text_AppendFormattedXYPair(out,0x58+((0x88-TextLayout_ComputeWidthWithGlyphSpacing(decorated,0))>>1),0x36);
Text_AppendFormatString(out,decorated);
short key=0x6d;
if(summary->special) key=(short)(summary->detail+0x7530);
text=(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),key);
Text_AppendFormattedXYPair(out,0x58+((0x88-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1),0x46);
Text_AppendFormatString(out,text);
char* state=(char*)summary+8;
int highlight=0;
if(self[0x1371]==14 && self[0x1370]>=1 && self[0x1370]<=4) state=*(char**)(self+0x13d0);
if(!*state) {
text=(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),0x12);
highlight=1;
} else text=(const char*)MessageTextTable_FindTextById((T*)(self+0x133c),0x13);
Text_AppendFormattedXYPair(out,0x58+((0x88-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1),0x56);
if(highlight) TextMarkup_AppendPaletteTag(out,3);
Text_AppendFormatString(out,text);
}
}
