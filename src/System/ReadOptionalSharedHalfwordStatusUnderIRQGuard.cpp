#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" {
extern char *data_021142e0[];
// Original: arm9/main @ 0x020D46CC; symbol: func_020d46cc; size: 0x30.
unsigned int ReadOptionalSharedHalfwordStatusUnderIRQGuard(){int old=DisableIRQInterrupts();char *p=data_021142e0[1];unsigned int v;if(p)v=*(unsigned short *)(p+0x150);else v=0;SetIRQInterruptState(old);return v;}
}
