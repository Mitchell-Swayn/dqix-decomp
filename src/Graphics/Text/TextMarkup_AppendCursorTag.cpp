#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char TextMarkup_AppendCursorTag_FormatCURSORD[];
// Original: arm9/main @ 0x02041EA4; symbol: func_02041ea4; size: 0x34.
    int TextMarkup_AppendCursorTag(char *out,int value){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,TextMarkup_AppendCursorTag_FormatCURSORD,value);
        return end-out;
    }
}
