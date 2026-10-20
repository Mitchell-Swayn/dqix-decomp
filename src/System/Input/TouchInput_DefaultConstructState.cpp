#include <globaldefs.h>
// Original: arm9/main @ 0x02012530; symbol: func_02012530; size: 0x4.
// Default construction of the static touch-input state performs no work.
// __sinit_020e66a0 calls this on data_02114e54 before registering its destructor.
// The sole instruction preserves the receiver in r0.
extern "C" ARM void* TouchInput_DefaultConstructState(void* receiver)
{
    return receiver;
}
