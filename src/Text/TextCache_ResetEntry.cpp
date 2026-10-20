#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0203BE8C; symbol: func_0203be8c; size: 0x30.
void TextCache_ResetEntry(char *p){memset(p,0,32);p[32]=0;p[33]=0;*(short *)(p+34)=-1;p[36]=0;}
}
