#include <globaldefs.h>
ARM
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" unsigned int BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
extern "C" void* Text_LookupStandardString(unsigned);
// Original data: arm9/ov002 @ 0x216ca04; symbol: data_ov002_0216ca04.
// Message IDs for six ordered text fields; Text_AppendSixResourceOptions indexes halfwords and passes IDs to func_020e51cc.
// Initial values: hex 110012001300140015001600.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" short TextAppendSixResourceOptions_MessageIDsForSixOrderedTextFields[];
// Original data: arm9/ov002 @ 0x216ca58; symbol: data_ov002_0216ca58.
// Text field display order; Text_AppendSixResourceOptions iterates six word entries.
// Initial values: hex 000000000300000001000000040000000200000005000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" int TextAppendSixResourceOptions_TextFieldDisplayOrder[];
// Original data: arm9/ov002 @ 0x216d26e; symbol: data_ov002_0216d26e.
// Source-defined character literal. Text: "\n". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "\n".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" char TextAppendSixResourceOptions_TextCodePoint10[];
// Original: arm9/ov002 @ 0x0215C178; symbol: func_ov002_0215c178; size: 0x150.
extern "C" void Text_AppendSixResourceOptions(char* obj,char* out,int prefix) {
 if(out) {
 int cursor=*(short*)(obj+0x1be0);
 void* global=GameState_GetSerializedProgressState();
 int enabled=BitArray_ReadNonnegativeIndexMask(global,(unsigned char*)global+0x8c,0x119a)!=0;
 int width=0;
 for(int i=0;i<3;i++) {
 int w=TextLayout_ComputeWidthWithGlyphSpacing((const char*)Text_LookupStandardString(TextAppendSixResourceOptions_MessageIDsForSixOrderedTextFields[i]),0);
 if(width<w) width=w;
 }
 if(prefix) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 for(int i=0;i<6;i++) {
 if(i==3 && !enabled) TextMarkup_AppendPaletteTag(out,3);
 int k=TextAppendSixResourceOptions_TextFieldDisplayOrder[i];
 Text_AppendFormattedIntegerAndStringFragment(out,k,(const char*)Text_LookupStandardString(TextAppendSixResourceOptions_MessageIDsForSixOrderedTextFields[k]));
 if(i==1 || i==3) Text_AppendFormatString(out,TextAppendSixResourceOptions_TextCodePoint10);
 else TextMarkup_AppendXPositionTag(out,width+32);
 if(i==3 && !enabled) TextMarkup_AppendPaletteTag(out,15);
 }
 }
}
