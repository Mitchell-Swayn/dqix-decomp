#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char data_020eff87[];
// Original: arm9/main @ 0x02041EA4; symbol: func_02041ea4; size: 0x34.
    int TextMarkup_AppendCursorTag(char *out,int value){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,data_020eff87,value);
        return end-out;
    }
}
