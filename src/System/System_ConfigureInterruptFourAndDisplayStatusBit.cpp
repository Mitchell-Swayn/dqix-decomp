#include <globaldefs.h>
ARM
#include <System/Interrupts.h>
extern "C" void ScanlineAlarm_HandleVCountInterrupt();extern "C" void Graphics_SetDisplayStatusVCountCompare(int);
struct Timer{char pad[16];short value;};
// Original: arm9/main @ 0x020C945C; symbol: func_020c945c; size: 0x40.
extern "C" void System_ConfigureInterruptFourAndDisplayStatusBit(Timer* p){SetInterruptHandler(4,(const void*)ScanlineAlarm_HandleVCountInterrupt);Graphics_SetDisplayStatusVCountCompare(p->value);*(volatile unsigned short*)0x04000004|=0x20;EnableSpecificInterrupts(4);}
