#pragma optimize_for_size off
#include <globaldefs.h>
ARM
#include "System/Interrupts.h"
#include "System/IPC.h"
extern "C" unsigned char data_021117ec[];extern "C" volatile int data_02111808;
// Original: arm9/main @ 0x020CE1D8; symbol: func_020ce1d8; size: 0x5C.
extern "C" void IPC_WaitForPendingCommandCompletion() {volatile int* pending=&data_02111808;volatile unsigned short* reg=(volatile unsigned short*)0x04000208;if(!*(int*)(data_021117ec+28))return;do{if(GetIRQInterruptState()==0x80||*reg==0||GetProcessorMode()==0x12)HandleCommandReceivedFromArm7();}while(*pending); }
