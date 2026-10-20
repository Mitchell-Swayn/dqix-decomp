#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char TextMarkup_AppendTalkWrappedText_FormatTALKSTALK[];
// Original: arm9/main @ 0x02041FE8; symbol: func_02041fe8; size: 0x34.
    int TextMarkup_AppendTalkWrappedText(char *out,int a0){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,TextMarkup_AppendTalkWrappedText_FormatTALKSTALK,a0);
        return end-out;
    }
}
