#pragma opt_propagation off
#pragma opt_arithtransformation off
#include <globaldefs.h>
// Original: arm9/main @ 0x020E03B8; symbol: func_020e03b8; size: 0x38.
ARM int ValidatePackedHeaderComputedSizeAgainstLength(void* unused,const unsigned int* header,unsigned int length) {
 unsigned int bits,small,large,size;
 if(!header || !length)return 0;
 bits=*header;small=(bits<<20)>>17;large=(bits<<1)>>13;size=small+4;size+=large;
 return size==length;
}
