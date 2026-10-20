#include <globaldefs.h>
ARM
extern "C" {
void* memset(void*,int,unsigned);
int sprintf(char*,const char*,...);
void __clear(void*,unsigned);
int TextMarkup_AppendXPositionTag(char*,int);
int Text_AppendFormattedXYPair(char*,int,int);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
int TextMarkup_AppendSizeTag(char*,int);
int TextMarkup_AppendPaletteTag(char*,int);
int TextMarkup_AppendUATag(char*,int,int,int);
int Text_AppendFormattedThreeIntegerFragment(char*,int,int,int);
int Text_AppendFormatString(char*,const char*);
const char* ResourceStringTable_GetTextByKey(void*,int);
// Original data: arm9/ov003 @ 0x2180156; symbol: data_ov003_02180156.
// Source-defined character literal. Text: "%d". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "%d".
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/ov003 @ 0x2180159; symbol: data_ov003_02180159.
// Source-defined character literal. Text: "0". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "0".
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern const char Graphics_AppendFlagAndSignedValueStatusPage_MarkupBlktriangle[],Graphics_AppendFlagAndSignedValueStatusPage_MarkupInvblktriangle[],GraphicsAppendFlagAndSignedValueStatusPage_TextD[],GraphicsAppendFlagAndSignedValueStatusPage_Text0[];
}
// Original: arm9/ov003 @ 0x02169D10; symbol: func_ov003_02169d10; size: 0x1DC.
extern "C" void Graphics_AppendFlagAndSignedValueStatusPage(unsigned char* p,char* out,int format) {
 if(!out) return;
 char buffer[2]={0};
 signed char row=*(signed char*)(p+0x4ee);
 int coordinate=row*8;
 Text_AppendFormattedXYPair(out,coordinate+0x23,5);
 if(p[0x5a6]) TextMarkup_AppendPaletteTag(out,13);
 else TextMarkup_AppendPaletteTag(out,15);
 Text_AppendFormatString(out,Graphics_AppendFlagAndSignedValueStatusPage_MarkupBlktriangle);
 Text_AppendFormattedXYPair(out,coordinate+0x23,27);
 if(p[0x5a7]) TextMarkup_AppendPaletteTag(out,13);
 else TextMarkup_AppendPaletteTag(out,15);
 Text_AppendFormatString(out,Graphics_AppendFlagAndSignedValueStatusPage_MarkupInvblktriangle);
 TextMarkup_AppendPaletteTag(out,15);
 if(format) TextMarkup_AppendFrameTag(out,row,3,11,3,10);
 TextMarkup_AppendUATag(out,row,p[0x5a6],2);
 Text_AppendFormattedThreeIntegerFragment(out,row,p[0x5a7],2);
 TextMarkup_AppendSizeTag(out,12);
 for(int i=0;i<7;i++) {
  memset(buffer,0,2);
  sprintf(buffer,GraphicsAppendFlagAndSignedValueStatusPage_TextD,*(signed char*)(p+0x4ef+i));
  Text_AppendFormattedXYPair(out,i*8+0x24,16);
  if(i<4) Text_AppendFormattedIntegerAndStringFragment(out,i,buffer);
  else Text_AppendFormatString(out,GraphicsAppendFlagAndSignedValueStatusPage_Text0);
 }
 TextMarkup_AppendXPositionTag(out,0x5c);
 Text_AppendFormatString(out,ResourceStringTable_GetTextByKey(p+0x64,0x66));
}
