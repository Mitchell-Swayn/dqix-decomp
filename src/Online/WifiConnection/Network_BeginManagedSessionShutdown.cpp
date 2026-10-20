#include <globaldefs.h>
THUMB
extern "C" ARM int _Z20DisableIRQInterruptsv(void);
extern "C" ARM int _Z20SetIRQInterruptStatei(int);
extern "C" ARM int Network_RequestWirelessPowerOff(void);
extern "C" ARM int Network_StopManagedSessionWirelessOperation(void);
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221F7FC; symbol: OV031_TryTransitionPendingState; size: 0x58.
// Disables IRQs while checking and transitioning the shared state, then restores the prior IRQ state.
THUMB
extern "C" int Network_BeginManagedSessionShutdown(void) { int irq=_Z20DisableIRQInterruptsv(); int state=*(int*)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage+44); if(state==3){int v=Network_RequestWirelessPowerOff(); if(v!=3){_Z20SetIRQInterruptStatei(irq);return 0;} *(int*)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage+44)=2;_Z20SetIRQInterruptStatei(irq);return 1;} int v=Network_StopManagedSessionWirelessOperation(); if(v==1){*(int*)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage+44)=2;_Z20SetIRQInterruptStatei(irq);return 1;} _Z20SetIRQInterruptStatei(irq);return 0;}
