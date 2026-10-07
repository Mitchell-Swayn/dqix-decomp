#include "System/Interrupts.h"

extern "C" unsigned int data_02112780[];

extern "C" unsigned int func_020d26ec()
{
    int interruptState = DisableIRQInterrupts();
    unsigned int active = data_02112780[2];
    unsigned int value;
    if (active == 0)
        value = data_02112780[1];
    else
        value = data_02112780[8];
    SetIRQInterruptState(interruptState);
    return value;
}
