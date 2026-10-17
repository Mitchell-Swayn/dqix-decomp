#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char data_020eff93[];
// Original: arm9/main @ 0x02041ED8; symbol: func_02041ed8; size: 0x4C.
    int AppendThreeFormattedArguments(char *out,int a0,int a1,int a2){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,data_020eff93,a0,a1,a2);
        return end-out;
    }
}
