#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02083B28; symbol: func_02083b28; size: 0x38.
extern "C" void ClearIndexedBitAt8EC(unsigned char* p,int bit) { unsigned char* bits=p+0x8ec;bits[bit/8]&=~(1U<<(bit%8)); }
