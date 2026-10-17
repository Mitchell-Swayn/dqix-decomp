#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void AppendKeyToGlobalTwentyFourHalfwordHistory(unsigned);
// Original: arm9/main @ 0x0206ECE8; symbol: func_0206ece8; size: 0x4C.
extern "C" ARM void NibbleArray_ClearSelectedNibble(unsigned unused,int index,unsigned char* p,unsigned size){int odd=index%2;unsigned i=index/2;if(i>=size){AppendKeyToGlobalTwentyFourHalfwordHistory(999);return;}if(odd)p[i]&=0xf0;else p[i]&=0xf;}
