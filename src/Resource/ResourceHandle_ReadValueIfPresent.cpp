#include <globaldefs.h>
ARM
extern "C" int NNS_SndHeapSaveState(void*);
// Original: arm9/main @ 0x0203AA64; symbol: func_0203aa64; size: 0x1C.
extern "C" int ResourceHandle_ReadValueIfPresent(void** p){if(!*p)return 0;return NNS_SndHeapSaveState(*p);}
