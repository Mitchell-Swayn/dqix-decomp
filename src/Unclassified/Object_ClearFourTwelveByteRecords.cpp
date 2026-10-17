#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02079870; symbol: func_02079870; size: 0x48.
void Object_ClearFourTwelveByteRecords(char *p){memset(p,0,12);memset(p+12,0,12);memset(p+24,0,12);memset(p+36,0,12);}
}
