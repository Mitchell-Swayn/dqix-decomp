#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/DTCM.h>
extern "C" void OS_Halt();
// Original: arm9/main @ 0x020C9778; symbol: func_020c9778; size: 0xA8.
extern "C" void WaitForInterruptMaskAndOptionallyClear(int clear,unsigned mask) {int irq=DisableIRQInterrupts();unsigned short ime=*(volatile unsigned short*)0x04000208;*(volatile unsigned short*)0x04000208=1;if(clear)((volatile DTCMData*)&data_027e0000)->interruptsFired &= ~mask;unsigned pending=((volatile DTCMData*)&data_027e0000)->interruptsFired;volatile unsigned* fired=&((volatile DTCMData*)&data_027e0000)->interruptsFired;if(!(mask & pending))do {OS_Halt();EnableIRQInterrupts();DisableIRQInterrupts();pending=*fired;}while(!(mask & pending));*fired &= ~mask;unsigned short discarded=*(volatile unsigned short*)0x04000208;*(volatile unsigned short*)0x04000208=ime;SetIRQInterruptState(irq);}
