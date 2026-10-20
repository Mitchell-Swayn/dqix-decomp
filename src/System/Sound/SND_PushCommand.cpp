#include <globaldefs.h>
ARM
#include <System/Interrupts.h>
struct SNDCommand { SNDCommand* next; unsigned command; unsigned arguments[4]; };
struct SoundCommandQueueState { SNDCommand* freeHead; unsigned counter; SNDCommand* reserveHead; SNDCommand* reserveTail; };
// Original data: arm9/main @ 0x2112780; symbol: data_02112780.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" SoundCommandQueueState SNDPushCommand_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020D248C; symbol: func_020d248c; size: 0x38.
// Appends a sound command to the reserved command queue with IRQs disabled.
// SDK reference SND_PushCommand: ntrtwl/NitroSDK@9eec6c92c9d7bba9350732b11296ed16aab3a8bc libraries/snd/src/snd_command.c:191.
extern "C" void SND_PushCommand(SNDCommand* command)
{
    int state = DisableIRQInterrupts();
    if (SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveTail == 0) {
        SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveHead = command;
        SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveTail = command;
    } else {
        SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveTail->next = command;
        SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveTail = command;
    }
    command->next = 0;
    SetIRQInterruptState(state);
}
