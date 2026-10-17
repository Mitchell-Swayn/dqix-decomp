#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" {
extern unsigned int data_02112780[];
// Original: arm9/main @ 0x020D26EC; symbol: func_020d26ec; size: 0x2C.
unsigned int ReadSelectedGlobalValueUnderIRQProtection(){int old=DisableIRQInterrupts();unsigned int v;if(data_02112780[2]==0)v=data_02112780[1];else v=data_02112780[8];SetIRQInterruptState(old);return v;}
}
