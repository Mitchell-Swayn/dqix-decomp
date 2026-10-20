#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original: arm9/main @ 0x020BC084; symbol: func_020bc084; size: 0x20.
extern "C" void ResourceHandle_ClearPointedValueAndOwner(unsigned* volatile* handle){if(!*handle)return;**handle=0;*handle=0;}
