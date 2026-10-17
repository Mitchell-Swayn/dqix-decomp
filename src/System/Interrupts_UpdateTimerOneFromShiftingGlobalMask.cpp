#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" {
extern unsigned int data_0214e4a0[];
// Original: arm9/main @ 0x020D8694; symbol: func_020d8694; size: 0x3C.
void Interrupts_UpdateTimerOneFromShiftingGlobalMask(){if(data_0214e4a0[1]&1)EnableSpecificInterrupts(4);else DisableSpecificInterrupts(4);data_0214e4a0[1]>>=1;}
}
