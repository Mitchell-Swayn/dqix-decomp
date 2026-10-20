#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
#pragma opt_propagation off
extern "C" unsigned int Network_GetWirelessWorkspace();
// Original: arm9/ov031 @ 0x0220F084; symbol: Network_GetDcfPeerGameInfo; size: 0x60.
// Returns the shared buffer and length only for state nine with byte 0x226B clear, under an IRQ guard.
// The wider shared-state layout remains unresolved.
extern "C" void* Network_GetDcfPeerGameInfo(unsigned short* length)
{
    void* buffer = NULL;
    unsigned short size = 0;
    unsigned char* shared = (unsigned char*)Network_GetWirelessWorkspace();
    int irq = DisableIRQInterrupts();
    if (shared != NULL && *(int*)(shared + 0x2260) == 9 && shared[0x226b] == 0)
    {
        size = *(unsigned short*)(shared + 0x214a);
        buffer = shared + 0x214c;
    }
    SetIRQInterruptState(irq);
    if (length) *length = size;
    return buffer;
}
