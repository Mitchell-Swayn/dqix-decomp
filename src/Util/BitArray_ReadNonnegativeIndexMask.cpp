#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0206DFB0; symbol: func_0206dfb0; size: 0x38.
extern "C" unsigned int BitArray_ReadNonnegativeIndexMask(void*,unsigned char* bits,int bit) { if(bit<0)return 0;unsigned char mask=1U<<(bit%8);return mask&bits[bit/8]; }
