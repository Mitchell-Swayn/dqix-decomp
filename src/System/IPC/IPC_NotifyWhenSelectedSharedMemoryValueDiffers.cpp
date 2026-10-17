#include <globaldefs.h>
#pragma optimize_for_size off
#include <System/Interrupts.h>
extern "C" void IPC_HandleCommandSeventeenOnceAndInvokeCallback(int,int,int);
// Original: arm9/main @ 0x020D1234; symbol: func_020d1234; size: 0x60.
extern "C" ARM void IPC_NotifyWhenSelectedSharedMemoryValueDiffers(int value){int* current;unsigned short* mode=(unsigned short*)0x027ffc10;if(*mode==0)current=(int*)((char*)mode-0x410);else current=(int*)((char*)mode-0x10);volatile int selected=*current;if(value!=selected){int state=DisableIRQInterrupts();IPC_HandleCommandSeventeenOnceAndInvokeCallback(14,17,0);SetIRQInterruptState(state);}}
