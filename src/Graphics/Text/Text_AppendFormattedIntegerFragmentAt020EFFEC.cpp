#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char data_020effec[];
// Original: arm9/main @ 0x02041FE8; symbol: func_02041fe8; size: 0x34.
    int Text_AppendFormattedIntegerFragmentAt020EFFEC(char *out,int a0){
        char *end=out+String_CountBytesUntilTerminator((const signed char *)out);
        end+=sprintf(end,data_020effec,a0);
        return end-out;
    }
}
