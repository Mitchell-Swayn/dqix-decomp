struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
struct Owner;struct Record;extern "C" void* memset(void*,int,unsigned);extern "C" void __clear(void*,unsigned);extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);extern "C" int Text_EncodeGlyphIndices(const char*,unsigned char*,unsigned);extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);extern "C" int TextMarkup_AppendXPositionTag(char*,int);extern "C" int Text_AppendFormatString(char*,const char*);extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);extern "C" int Window_ReplaceCanvasTextById(Owner*,unsigned,void*,unsigned,unsigned char);
// Original: arm9/ov023 @ 0x021d9e60; symbol: Text_RebuildSelectedEightGlyphCanvas.
extern "C" void Text_RebuildSelectedEightGlyphCanvas(unsigned char* s){
if(!(W(s,0xd9c)&0x8000))return;char* text=(char*)P(s,0xf8);memset(text,0,2400);
if(*(signed char*)(s+0xc58)==8){unsigned char* record=(unsigned char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(s+0x2b4)),3);U(record,0xb8)=17;U(record,0xba)=16;unsigned char glyph[128];unsigned char mapped[128];__clear(glyph,128);__clear(mapped,128);int n=Text_EncodeGlyphIndices(((char**)P(s,0xdb0))[s[0xda3]],glyph,0);for(;n<8;n++)glyph[n]=s[0xdb4];Text_MapInputBytesToVariableLengthOutputSequences(glyph,mapped,0);int width=TextLayout_ComputeWidthWithGlyphSpacing((char*)mapped,0);TextMarkup_AppendXPositionTag(text,(80-width)>>1);Text_AppendFormatString(text,(char*)mapped);}else Text_AppendFormatString(text,(char*)ResourceStringTable_GetTextByKey(s+0xe0,(void*)0x4274));
Window_ReplaceCanvasTextById((Owner*)(s+0x2b4),3,text,0,0);W(s,0xd9c)&=~0x8000;
}
