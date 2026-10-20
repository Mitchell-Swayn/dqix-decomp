#include <globaldefs.h>
THUMB
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned _Z20DisableIRQInterruptsv(...);
extern "C" unsigned _Z20SetIRQInterruptStatei(...);
extern "C" unsigned Network_InitializeWirelessWorkspace(...);
extern "C" unsigned Network_StartWirelessInitializationUnderIRQ(...);
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224f6f0; symbol: data_ov031_0224f6f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkHandleManagedSessionWirelessEvent_UnknownRoleZeroInitializedStorage[];
extern "C" void Network_HandleManagedSessionWirelessEvent();
// Original: arm9/ov031 @ 0x0221F8D8; symbol: InitializeAlignedWorkspaceAndSubmitState; size: 0xbc.
// Aligns workspace header and two regions under IRQ protection, submits initialization state and restores interrupts.
extern "C" int Network_InitializeManagedSessionWorkspace(unsigned callback,unsigned memory,unsigned size){
 unsigned irq=_Z20DisableIRQInterruptsv();unsigned header=(memory+0x63)&~3;U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,0x28)=memory;U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,8)=header;
 unsigned first=(header+0x2f)&~31;U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,0x3c)=first;unsigned second=(first+0x231f)&~31;U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,0x4c)=second;U(header,4)=(second+0xdf)&~31;
 U(U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,8),8)=memory+size-U(U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,8),4);U(U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,8),12)=0;U(U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,8),0)=3;U(NetworkHandleManagedSessionWirelessEvent_UnknownRoleZeroInitializedStorage,0)=callback;
 if(!U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,0x2c)){if(Network_InitializeWirelessWorkspace(U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,0x3c),0x2300)){_Z20SetIRQInterruptStatei(irq);return 0;}U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,0x2c)=1;}
 if(U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,0x2c)==1){if(Network_StartWirelessInitializationUnderIRQ(U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,8),Network_HandleManagedSessionWirelessEvent)!=3){_Z20SetIRQInterruptStatei(irq);return 0;}U(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage,0x2c)=4;_Z20SetIRQInterruptStatei(irq);return 1;}
 _Z20SetIRQInterruptStatei(irq);return 0;
}
