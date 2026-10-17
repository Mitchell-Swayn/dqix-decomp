#include <globaldefs.h>
ARM
#include <System/IPC.h>
#include <System/Interrupts.h>
extern "C" int WirelessCommand_ReadInitializedStatus();extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int);extern "C" void System_ClearSharedHalfword96BitZero();struct CommandState {unsigned short active,pad;unsigned pending;};extern "C" CommandState data_021142e0;
// Original: arm9/main @ 0x020D3FDC; symbol: func_020d3fdc; size: 0x70.
extern "C" int ResetIPCOperationStateUnderIRQProtection(){int irq=DisableIRQInterrupts();if(WirelessCommand_ReadInitializedStatus()){SetIRQInterruptState(irq);return 3;}int r=TestCurrentStatusAgainstVariadicAllowedValues(1,0);if(r)return r;System_ClearSharedHalfword96BitZero();SetArm9IPCCommandHandler(10,0);data_021142e0.pending=0;data_021142e0.active=0;SetIRQInterruptState(irq);return 0;}
