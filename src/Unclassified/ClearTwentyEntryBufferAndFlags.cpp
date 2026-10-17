#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void VectorizedMemset(void*,unsigned,unsigned);
// Original: arm9/main @ 0x02026644; symbol: func_02026644; size: 0x34.
extern "C" void ClearTwentyEntryBufferAndFlags(unsigned char* p){if(p[18]){p[0x779]=0;p[0x9ba]=0;}p[0x780]=0;VectorizedMemset(p+0x784,0,0x230);}
