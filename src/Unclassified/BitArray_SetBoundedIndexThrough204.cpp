#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0209609C; symbol: func_0209609c; size: 0x30.
void BitArray_SetBoundedIndexThrough204(int unused,unsigned char *p,int i){if(i>204)return;if(i<0)return;unsigned char mask=1<<(i&7);p[i>>3]|=mask;}
}
