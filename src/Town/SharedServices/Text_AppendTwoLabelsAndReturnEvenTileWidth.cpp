#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void __clear(void*,unsigned);char* ResourceStringTable_GetTextByKey(void*,unsigned);int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);int sprintf(char*,const char*,...);int Text_AppendFormatString(void*,const char*);extern char Text_AppendTwoLabelsAndReturnEvenTileWidth_FormatN0SN[],Text_AppendTwoLabelsAndReturnEvenTileWidth_FormatN1SN[];}
// Original: arm9/ov003 @ 0x0216DF38; symbol: Text_AppendTwoLabelsAndReturnEvenTileWidth; size: 0xf4.
// Appends two labels and trailing formatted text, returning an even tile width.
extern "C" short Text_AppendTwoLabelsAndReturnEvenTileWidth(void* output,void* records,int alternate){char buffer[128];int width;__clear(buffer,128);int id=5;if(alternate)id=6;char* first=ResourceStringTable_GetTextByKey(records,id);char* second=ResourceStringTable_GetTextByKey(records,7);width=TextLayout_ComputeWidthWithGlyphSpacing(first,0);int next=TextLayout_ComputeWidthWithGlyphSpacing(second,0);if(width<next)width=next;sprintf(buffer,Text_AppendTwoLabelsAndReturnEvenTileWidth_FormatN0SN,first);Text_AppendFormatString(output,buffer);sprintf(buffer,Text_AppendTwoLabelsAndReturnEvenTileWidth_FormatN1SN,second);Text_AppendFormatString(output,buffer);sprintf(buffer,ResourceStringTable_GetTextByKey(records,14));Text_AppendFormatString(output,buffer);int aligned=(width+27)&~7;int tiles=aligned>>3;return(short)(tiles+(tiles&1));}
