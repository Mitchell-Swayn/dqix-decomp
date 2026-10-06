#include "System/Interrupts.h"

extern "C" volatile unsigned int data_0214e4a0[];

extern "C" void func_020d8694()
{
    if ((data_0214e4a0[1] & 1) != 0)
        EnableSpecificInterrupts(4);
    else
        DisableSpecificInterrupts(4);

    data_0214e4a0[1] >>= 1;
}
