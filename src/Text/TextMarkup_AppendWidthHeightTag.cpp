#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
// Original data: arm9/main @ 0x20efe9f; symbol: data_020efe9f.
// Source-defined character literal. Text: "<WH=%d,%d>". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "<WH=%d,%d>".
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern char TextMarkupAppendWidthHeightTag_TextWHDDWithAdjacentText[];
// Original: arm9/main @ 0x02041B34; symbol: func_02041b34; size: 0x3C.
    int TextMarkup_AppendWidthHeightTag(char *out,int a0,int a1){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,TextMarkupAppendWidthHeightTag_TextWHDDWithAdjacentText,a0,a1);
        return end-out;
    }
}
