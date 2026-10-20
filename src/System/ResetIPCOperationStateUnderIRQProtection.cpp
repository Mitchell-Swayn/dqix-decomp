#include <globaldefs.h>
ARM
#include <System/IPC.h>
#include <System/Interrupts.h>
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int WirelessCommand_ReadInitializedStatus();extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int);extern "C" void System_ClearSharedHalfword96BitZero();struct CommandState {unsigned short active,pad;unsigned pending;};extern "C" CommandState WMiCheckIdle_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020D3FDC; symbol: func_020d3fdc; size: 0x70.
extern "C" int ResetIPCOperationStateUnderIRQProtection(){int irq=DisableIRQInterrupts();if(WirelessCommand_ReadInitializedStatus()){SetIRQInterruptState(irq);return 3;}int r=TestCurrentStatusAgainstVariadicAllowedValues(1,0);if(r)return r;System_ClearSharedHalfword96BitZero();SetArm9IPCCommandHandler(10,0);WMiCheckIdle_UnknownRoleZeroInitializedStorage.pending=0;WMiCheckIdle_UnknownRoleZeroInitializedStorage.active=0;SetIRQInterruptState(irq);return 0;}
