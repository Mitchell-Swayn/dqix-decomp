#include <globaldefs.h>
ARM
extern "C" unsigned _u32_div_f(unsigned,unsigned);
// Original: arm9/main @ 0x020A090C; symbol: func_020a090c; size: 0x30.
extern "C" unsigned ComputePercentOf448WithNonzeroMinimumOne(unsigned* p){unsigned n=p[4]>>23;unsigned percent=_u32_div_f(n*100,448);if(percent)return percent;if(n)percent=1;return percent;}
