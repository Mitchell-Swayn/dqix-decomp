#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" volatile signed char data_020e7e10[],data_020e7e1c[];
// Original: arm9/main @ 0x0206B804; symbol: func_0206b804; size: 0x58.
extern "C" ARM void ReadActiveDirectionVectorAndMarkPendingUpdate(unsigned char* self,int* x,int* y) { *y=0; *x=0; if(!self[0x19c0])return; self[0x19cd]=1; *(int*)(self+64)=0; unsigned int direction=self[0x195d]&3; signed char dx=data_020e7e10[direction]; signed char dy=data_020e7e1c[direction]; *x=dx;*y=dy; }
