#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    extern char data_020f2b6c[];
    extern char data_020f2b71[];
// Original: arm9/main @ 0x020E05F8; symbol: func_020e05f8; size: 0x44.
    bool FormatTextAndReplaceMatchingSuffix(char *p,const char *format){
        if(!p||!format)return false;
        sprintf(p,format);
        char *suffix=strstr(p,data_020f2b6c);
        if(suffix)strcpy(suffix,data_020f2b71);
        return true;
    }
}
