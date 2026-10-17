#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char data_020efe9f[];
// Original: arm9/main @ 0x02041B34; symbol: func_02041b34; size: 0x3C.
    int AppendFormattedPair_Main02041B34(char *out,int a0,int a1){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,data_020efe9f,a0,a1);
        return end-out;
    }
}
