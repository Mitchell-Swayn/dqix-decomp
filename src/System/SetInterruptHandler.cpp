#include "System/DTCM.h"
#include "System/Interrupts.h"
#include "System/InterruptResponse.h"
#include "System/BiosData.h"
#pragma optimize_for_size off
// Original: arm9/main @ 0x020C6AEC; symbol: _Z19SetInterruptHandlerjPKv; size: 0x88.
void SetInterruptHandler(unsigned int mask, const void* proc)
{


    int interruptID;
    DMAOrTimerResponse* empty = NULL;

    interruptID = 0;
    do {

        if (mask & 1)
        {
            DMAOrTimerResponse* dmaTimerData = empty;
            // DMA channels
            if (interruptID >= 8 && interruptID <= 11)
            {
                dmaTimerData = &data_0211127c[interruptID - 8];
            }
            // timer overflows
            else if (interruptID >= 3 && interruptID <= 6)
            {
                dmaTimerData = &data_0211127c[interruptID + 1];
            }
            else
            {
                data_027e0000.interruptProcTable[interruptID] = (InterruptHandlerProc)proc;
            }

            if (dmaTimerData != NULL)
            {
                dmaTimerData->callback = (DMACompletionCallback)proc;
                dmaTimerData->userdata = 0;
                dmaTimerData->stayEnabledAfter = true;
            }
        }
        interruptID++;
        mask >>= 1;
    } while (interruptID < 22);
}