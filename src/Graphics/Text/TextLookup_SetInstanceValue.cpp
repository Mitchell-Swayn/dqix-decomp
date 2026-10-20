#include <globaldefs.h>
extern "C" {
void *TextLookup_SelectFontTableForFont(void);
void Text_FormatAbsoluteIntegerAndMeasureWidth(void *, unsigned int);
// Original: arm9/main @ 0x020426A4; symbol: func_020426a4; size: 0x18.
ARM void TextLookup_SetInstanceValue(unsigned int param_1, unsigned int param_2) {
    void *instance = TextLookup_SelectFontTableForFont();
    Text_FormatAbsoluteIntegerAndMeasureWidth(instance, param_2);
}
}
