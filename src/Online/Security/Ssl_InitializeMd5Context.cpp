#include <globaldefs.h>
extern "C" void VectorizedMemset(void*,int,unsigned int);
// Original: arm9/ov031 @ 0x0220AFE0; symbol: func_ov031_0220afe0; size: 0x48.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void Ssl_InitializeMd5Context(unsigned int* p) {
 VectorizedMemset(p,0,88); p[0]=0x67452301; p[1]=0xefcdab89; p[2]=0x98badcfe; p[3]=0x10325476;
}
