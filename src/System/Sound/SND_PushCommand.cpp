#include <globaldefs.h>
ARM
#include <System/Interrupts.h>
struct SNDCommand { SNDCommand* next; unsigned command; unsigned arguments[4]; };
struct SoundCommandQueueState { SNDCommand* freeHead; unsigned counter; SNDCommand* reserveHead; SNDCommand* reserveTail; };
extern "C" SoundCommandQueueState data_02112780;
// Original: arm9/main @ 0x020D248C; symbol: func_020d248c; size: 0x38.
// Appends a sound command to the reserved command queue with IRQs disabled.
// SDK reference SND_PushCommand: ntrtwl/NitroSDK@9eec6c92c9d7bba9350732b11296ed16aab3a8bc libraries/snd/src/snd_command.c:191.
extern "C" void SND_PushCommand(SNDCommand* command)
{
    int state = DisableIRQInterrupts();
    if (data_02112780.reserveTail == 0) {
        data_02112780.reserveHead = command;
        data_02112780.reserveTail = command;
    } else {
        data_02112780.reserveTail->next = command;
        data_02112780.reserveTail = command;
    }
    command->next = 0;
    SetIRQInterruptState(state);
}
