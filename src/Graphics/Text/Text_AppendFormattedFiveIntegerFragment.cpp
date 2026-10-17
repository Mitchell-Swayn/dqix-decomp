#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char data_020efefb[];
// Original: arm9/main @ 0x02041C64; symbol: func_02041c64; size: 0x5C.
    int Text_AppendFormattedFiveIntegerFragment(char *out,int a0,int a1,int a2,int a3,int a4){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,data_020efefb,a0,a1,a2,a3,a4);
        return end-out;
    }
}
