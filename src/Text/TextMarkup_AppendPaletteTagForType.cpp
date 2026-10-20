#include <globaldefs.h>
ARM
extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);extern "C" const char TextMarkup_AppendPaletteTagForType_MarkupPLTT15[],TextMarkup_AppendPaletteTagForType_MarkupPLTT11[],TextMarkup_AppendPaletteTagForType_MarkupPLTT13[],TextMarkup_AppendPaletteTagForType_MarkupPLTT9[];
// Original: arm9/main @ 0x02041DD0; symbol: func_02041dd0; size: 0xA0.
extern "C" int TextMarkup_AppendPaletteTagForType(char* text,unsigned type) { char* end=text+String_CountBytesUntilTerminator(text);switch(type) {case 0:end+=sprintf(end,TextMarkup_AppendPaletteTagForType_MarkupPLTT15);break;case 1:break;case 2:break;case 3:break;case 5:end+=sprintf(end,TextMarkup_AppendPaletteTagForType_MarkupPLTT11);break;case 4:end+=sprintf(end,TextMarkup_AppendPaletteTagForType_MarkupPLTT13);break;case 6:end+=sprintf(end,TextMarkup_AppendPaletteTagForType_MarkupPLTT9);break;}return end-text; }
