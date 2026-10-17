#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" volatile unsigned data_0211166c;extern "C" volatile unsigned short data_02111670[];extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);extern "C" int OsCountZeroBits(unsigned);
// Original: arm9/main @ 0x020C9A88; symbol: func_020c9a88; size: 0x88.
extern "C" void System_ReleaseOwnedInterruptSlots(unsigned mask,unsigned owner){unsigned pending;int irq=_Z20DisableIRQInterruptsv();pending=mask&data_0211166c&0x1ff;for(;;){int index=31-OsCountZeroBits(pending);if(index<0)break;unsigned clear=~(1u<<index);pending&=clear;if(owner==data_02111670[index]){unsigned enabled=data_0211166c;data_02111670[index]=0;data_0211166c=enabled&clear;}}_Z20SetIRQInterruptStatei(irq);}
