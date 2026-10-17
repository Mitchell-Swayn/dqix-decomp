#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02083ACC; symbol: func_02083acc; size: 0x34.
extern "C" void SetMaskedFlagsAtOffset8EC(unsigned char* p,int bit) { unsigned char* bits=p+0x8ec;bits[bit/8]|=1U<<(bit%8); }
