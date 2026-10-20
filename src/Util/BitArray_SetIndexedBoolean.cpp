#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0206DF6C; symbol: func_0206df6c; size: 0x44.
extern "C" void BitArray_SetIndexedBoolean(void*, unsigned char* bits, int index, int enabled) { int bit=index%8;int byte=index/8;unsigned char mask=1 << bit; unsigned int value=bits[byte]; if(enabled) value|=mask; else value&=~mask; bits[byte]=value; }
