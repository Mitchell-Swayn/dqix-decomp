#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void ClearTwentyEntryBufferAndFlags(void*);
// Original: arm9/main @ 0x02026678; symbol: func_02026678; size: 0x1C.
extern "C" void SetByteField9B8AndResetDependentState(unsigned char* p){p[0x9b8]=1;p[0x9b9]=0;ClearTwentyEntryBufferAndFlags(p);}
