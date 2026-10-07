extern "C" int func_020c7dc4();
#include "System/Interrupts.h"

extern "C" int func_020d28f0()
{
    if (func_020c7dc4() == 0)
    {
        return 1;
    }

    int interruptState = DisableIRQInterrupts();
    volatile unsigned int* requestState = (volatile unsigned int*)0x04fff200;
    *requestState = 0x10;
    unsigned int requestedState = *requestState;
    SetIRQInterruptState(interruptState);

    return requestedState != 0;
}
