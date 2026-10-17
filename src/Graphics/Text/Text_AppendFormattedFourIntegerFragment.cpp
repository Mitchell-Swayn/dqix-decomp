#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char data_020eff2f[];
// Original: arm9/main @ 0x02041D48; symbol: func_02041d48; size: 0x54.
    int Text_AppendFormattedFourIntegerFragment(char *out,int a0,int a1,int a2,int a3){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,data_020eff2f,a0,a1,a2,a3);
        return end-out;
    }
}
