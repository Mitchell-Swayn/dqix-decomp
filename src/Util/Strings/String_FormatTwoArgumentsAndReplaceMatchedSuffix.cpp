#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
extern char data_020f2e20[],data_020f2e25[];
// Original: arm9/main @ 0x020E55C0; symbol: func_020e55c0; size: 0x44.
bool String_FormatTwoArgumentsAndReplaceMatchedSuffix(char *p,const char *format,int a,int b){if(!p||!format)return false;sprintf(p,format,a,b);char *q=strstr(p,data_020f2e20);if(q)strcpy(q,data_020f2e25);return true;}
}
