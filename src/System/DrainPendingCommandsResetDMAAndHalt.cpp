#include <globaldefs.h>
#include <System/DMA.h>
#include <System/Interrupts.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int PowerManagement_RunSynchronousOperationWithTemporaryCallback(void);
extern "C" void OS_SpinWait(unsigned int);
extern "C" void OS_Halt(void);
// Original: arm9/main @ 0x020CE7A4; symbol: func_020ce7a4; size: 0x3C.
extern "C" void DrainPendingCommandsResetDMAAndHalt(void) {
    int pending = PowerManagement_RunSynchronousOperationWithTemporaryCallback();
    if (pending != 0) {
        register unsigned int item = 0xa3a47;
        do {
            OS_SpinWait(item);
            pending = PowerManagement_RunSynchronousOperationWithTemporaryCallback();
        } while (pending != 0);
    }
    DisableIRQInterrupts();
    ResetAllDMAChannels();
    for (;;) OS_Halt();
}
