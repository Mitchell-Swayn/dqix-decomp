#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020E4798; symbol: func_020e4798; size: 0x24.
char *String_AppendOptionalTwoArgumentFormat(char *p,const char **q,int a,int b){const char *format=q[1];if(format)p+=sprintf(p,format,a,b);return p;}
}
