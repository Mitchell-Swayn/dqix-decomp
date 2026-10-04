#include "System/Interrupts.h"
#include "System/InterruptResponse.h"
#include "System/DTCM.h"

#pragma optimize_for_size off

inline DMACompletionCallback& CallbackByIndex(int n, int base = 0)
{
    return *(DMACompletionCallback*)((unsigned int)&data_0211127c[base].callback + n * sizeof(DMAOrTimerResponse));
}

inline unsigned int& ShouldStayEnabledByIndex(int n, int base = 0)
{
    return *(unsigned int*)((unsigned int)&data_0211127c[base].stayEnabledAfter + n * sizeof(DMAOrTimerResponse));
}

inline int& CallbackUserdataByIndex(int n, int base = 0)
{
    return *(int*)((unsigned int)&data_0211127c[base].userdata + n * sizeof(DMAOrTimerResponse));
}

InterruptHandlerProc GetInterruptHandler(unsigned int mask)
{
    int interruptId = 0;
    InterruptHandlerProc* pProc = &data_027e0000.interruptProcTable[0];
    do
    {
        if (!(mask & 1))
            continue;

        if (interruptId >= 8 && interruptId <= 11)
        {
            return (InterruptHandlerProc)data_0211127c[interruptId - 8].callback;
        }
        else if (interruptId >= 3 && interruptId <= 6)
        {
            return (InterruptHandlerProc)data_0211127c[interruptId + 1].callback;
        }
        else
        {
            return *pProc;
        }

    } while (interruptId++, mask >>= 1, pProc++, interruptId < 22);
    return NULL;
}

void SetDMACompletionCallback(int channel, DMACompletionCallback callback, int userdata)
{
    CallbackByIndex(channel) = callback;
    CallbackUserdataByIndex(channel) = userdata;
    unsigned int prior = EnableSpecificInterrupts(1 << (channel + 8));
    ShouldStayEnabledByIndex(channel) = prior & (1 << (channel + 8));
}

void SetTimerOverflowCallback(int timer, DMACompletionCallback callback, int userdata)
{
    CallbackByIndex(timer, 4) = callback;
    CallbackUserdataByIndex(timer, 4) = userdata;
    EnableSpecificInterrupts(1 << (timer + 3));
    ShouldStayEnabledByIndex(timer, 4) = true;
}
