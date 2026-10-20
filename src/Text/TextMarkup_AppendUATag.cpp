#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
// Original data: arm9/main @ 0x20eff93; symbol: data_020eff93.
// Source-defined character literal. Text: "<UA=%d,%d,%d>". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "<UA=%d,%d,%d>".
// Observed span: 42 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern char TextMarkupAppendUATag_TextUADDDWithAdjacentText[];
// Original: arm9/main @ 0x02041ED8; symbol: func_02041ed8; size: 0x4C.
    int TextMarkup_AppendUATag(char *out,int a0,int a1,int a2){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,TextMarkupAppendUATag_TextUADDDWithAdjacentText,a0,a1,a2);
        return end-out;
    }
}
