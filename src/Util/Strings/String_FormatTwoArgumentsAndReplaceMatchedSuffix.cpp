#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
extern char String_FormatTwoArgumentsAndReplaceMatchedSuffix_TextBin[],String_FormatTwoArgumentsAndReplaceMatchedSuffix_TextNat[];
// Original: arm9/main @ 0x020E55C0; symbol: func_020e55c0; size: 0x44.
bool String_FormatTwoArgumentsAndReplaceMatchedSuffix(char *p,const char *format,int a,int b){if(!p||!format)return false;sprintf(p,format,a,b);char *q=strstr(p,String_FormatTwoArgumentsAndReplaceMatchedSuffix_TextBin);if(q)strcpy(q,String_FormatTwoArgumentsAndReplaceMatchedSuffix_TextNat);return true;}
}
