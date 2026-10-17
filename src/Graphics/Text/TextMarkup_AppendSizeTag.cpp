#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char data_020eff43[];
// Original: arm9/main @ 0x02041D9C; symbol: func_02041d9c; size: 0x34.
    int TextMarkup_AppendSizeTag(char *out,int value){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,data_020eff43,value);
        return end-out;
    }
}
