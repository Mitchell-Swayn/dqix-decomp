#include <globaldefs.h>
extern "C" unsigned int data_ov000_02184220;
// Original: arm9/ov000 @ 0x02160D80; symbol: func_ov000_02160d80; size: 0x20.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void SetPendingFieldEA8(unsigned char* p,unsigned int value) {
 *(unsigned int*)(p+0xea8)=value; *(unsigned int*)(p+0xeac)=0; data_ov000_02184220=1;
}
