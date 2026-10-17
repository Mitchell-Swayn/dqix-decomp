#include <globaldefs.h>
ARM
extern "C" void _Z18AwaitDMACompletioni(int);extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" int data_020f226c[2];
// Original: arm9/main @ 0x020C3A0C; symbol: func_020c3a0c; size: 0x40.
extern "C" int AwaitPreviousDMAAndSwapChannelUnderIRQProtection(int next){int old=data_020f226c[1];if(old!=-1)_Z18AwaitDMACompletioni(old);int irq=_Z20DisableIRQInterruptsv();data_020f226c[1]=next;_Z20SetIRQInterruptStatei(irq);return old;}
