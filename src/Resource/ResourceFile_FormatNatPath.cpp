#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    extern char ResourceFile_FormatNatPath_TextBin[];
    extern char ResourceFile_FormatNatPath_TextNat[];
// Original: arm9/main @ 0x020E05F8; symbol: func_020e05f8; size: 0x44.
    bool ResourceFile_FormatNatPath(char *p,const char *format){
        if(!p||!format)return false;
        sprintf(p,format);
        char *suffix=strstr(p,ResourceFile_FormatNatPath_TextBin);
        if(suffix)strcpy(suffix,ResourceFile_FormatNatPath_TextNat);
        return true;
    }
}
