#include "System/Interrupts.h"

extern "C" unsigned int data_02112780[];

extern "C" int func_020d2718(unsigned int value)
{
    int previousState = DisableIRQInterrupts();
    volatile unsigned int* timer = (volatile unsigned int*)data_02112780;
    unsigned int threshold = timer[1];
    unsigned int difference;
    unsigned int result;

    if (value > threshold) {
        difference = value - threshold;
        if (difference < 0x80000000u)
            result = 0;
        else
            result = 1;
    } else {
        difference = threshold - value;
        result = difference < 0x80000000u ? 1u : 0u;
    }

    SetIRQInterruptState(previousState);
    return (int)result;
}
