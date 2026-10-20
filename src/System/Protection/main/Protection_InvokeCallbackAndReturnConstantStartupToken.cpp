#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020D6BE4; symbol: func_020d6be4; size: 0x1C.
    unsigned int Protection_InvokeCallbackAndReturnConstantStartupToken(void (*callback)()){
        if(callback)callback();
        return 0xffe412c4;
    }
}
