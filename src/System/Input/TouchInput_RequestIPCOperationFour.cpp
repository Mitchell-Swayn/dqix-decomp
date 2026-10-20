#include <globaldefs.h>
#include "System/Interrupts.h"
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int SendCommandToArm7(int,int,bool);struct Control{unsigned unused;void(*callback)(int,int,int);char pad[0x30];unsigned short pending,ready;};extern "C" Control TPWaitBusy_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020CDBE4; symbol: func_020cdbe4; size: 0x98.
extern "C" ARM void TouchInput_RequestIPCOperationFour(){int irq=DisableIRQInterrupts();int result=SendCommandToArm7(6,0x3000200,false);int success=result>=0;if(!success){SetIRQInterruptState(irq);TPWaitBusy_UnknownRoleZeroInitializedStorage.pending|=4;if(!TPWaitBusy_UnknownRoleZeroInitializedStorage.callback)return;TPWaitBusy_UnknownRoleZeroInitializedStorage.callback(2,4,0);return;}TPWaitBusy_UnknownRoleZeroInitializedStorage.ready|=4;TPWaitBusy_UnknownRoleZeroInitializedStorage.pending&=~4;SetIRQInterruptState(irq);}
