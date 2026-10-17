#include <globaldefs.h>
#include "System/Interrupts.h"
extern int SendCommandToArm7(int,int,bool);struct Control{unsigned unused;void(*callback)(int,int,int);char pad[0x30];unsigned short pending,ready;};extern "C" Control data_021117b0;
// Original: arm9/main @ 0x020CDBE4; symbol: func_020cdbe4; size: 0x98.
extern "C" ARM void TouchInput_RequestIPCOperationFour(){int irq=DisableIRQInterrupts();int result=SendCommandToArm7(6,0x3000200,false);int success=result>=0;if(!success){SetIRQInterruptState(irq);data_021117b0.pending|=4;if(!data_021117b0.callback)return;data_021117b0.callback(2,4,0);return;}data_021117b0.ready|=4;data_021117b0.pending&=~4;SetIRQInterruptState(irq);}
