#include "System/Interrupts.h"

extern "C" volatile unsigned int data_0214e4a0[];

extern "C" void func_020d8654()
{
    data_0214e4a0[1] <<= 1;

    const unsigned int previousInterrupts = DisableSpecificInterrupts(4);
    data_0214e4a0[1] |= (previousInterrupts & 4) != 0;
}
