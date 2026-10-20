#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int WirelessCommand_InitializeAndClearSharedHalfword16(unsigned,unsigned);
extern "C" int ResetIPCOperationStateUnderIRQProtection();
extern "C" int WM_SetIndCallback(unsigned);
extern "C" unsigned WM_GetAllowedChannel();
extern "C" int WM_Enable(void*);
extern "C" void Network_ConfigureAccessPointListAndCallback(unsigned*,int);
extern "C" void Network_SetWirelessStateAndConnectionAlarm(int);
extern "C" void System_HandleSpecificContextEvent(const unsigned short* message);
extern "C" void Network_HandleWirelessLifecycleCommandResult();
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x0220CAE0; symbol: func_ov031_0220cae0; size: 0x204.
// Starts wireless initialization from shared state1, maps operation errors and restores IRQ state on every exit.
extern "C" int Network_StartWirelessInitializationUnderIRQ(unsigned* config,int callback){
int irq=_Z20DisableIRQInterruptsv();
if(!NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage){SetIRQInterruptState(irq);return 1;}
switch(F(unsigned,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2260)){
case 1:Network_ConfigureAccessPointListAndCallback(config,callback);break;
case 2:SetIRQInterruptState(irq);return 2;
case 3:SetIRQInterruptState(irq);return 0;
default:SetIRQInterruptState(irq);return 1;
}
switch(WirelessCommand_InitializeAndClearSharedHalfword16((unsigned)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,(unsigned short)F(unsigned,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x226c))){
case 0:break;
case 3:Network_SetWirelessStateAndConnectionAlarm(11);SetIRQInterruptState(irq);return 7;
case 4:SetIRQInterruptState(irq);return 5;
case 1:case 2:case 5:case 6:default:Network_SetWirelessStateAndConnectionAlarm(11);SetIRQInterruptState(irq);return 7;
}
if(WM_GetAllowedChannel()==0){if(ResetIPCOperationStateUnderIRQProtection()){Network_SetWirelessStateAndConnectionAlarm(11);SetIRQInterruptState(irq);return 7;}SetIRQInterruptState(irq);return 5;}
if(WM_SetIndCallback((unsigned)System_HandleSpecificContextEvent)){Network_SetWirelessStateAndConnectionAlarm(11);SetIRQInterruptState(irq);return 7;}
switch(WM_Enable((void*)Network_HandleWirelessLifecycleCommandResult)){
case 2:Network_SetWirelessStateAndConnectionAlarm(2);F(unsigned short,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2280)=1;break;
case 8:Network_SetWirelessStateAndConnectionAlarm(12);SetIRQInterruptState(irq);return 1;
case 3:default:Network_SetWirelessStateAndConnectionAlarm(11);SetIRQInterruptState(irq);return 7;
}
SetIRQInterruptState(irq);return 3;
}
