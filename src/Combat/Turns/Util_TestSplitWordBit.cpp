#include <globaldefs.h>

// Original: arm9/ov000 @ 0x0215FD90; symbol: func_ov000_0215fd90; size: 0x70.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM int Util_TestSplitWordBit(unsigned long long* p,unsigned int bit) {
 unsigned long long value;
 if(bit>31) value=*p & ((-1ULL <<32)&((long long)(1 << (bit-31))<<32));
 else value=*p & (0x00000000ffffffffULL & (long long)(1 << bit));
 return value!=0;
}
