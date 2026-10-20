#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int WM_PowerOff(void*);
extern "C" void Network_SetWirelessStateAndConnectionAlarm(int);
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
extern "C" void Network_HandleWirelessLifecycleCommandResult();
// Original: arm9/ov031 @ 0x0220CCE4; symbol: PollSharedCommandSixStatus; size: 0xf0.
// Polls shared state under IRQ exclusion and maps command-six results.
extern "C" int Network_RequestWirelessPowerOff(){
 int irq=_Z20DisableIRQInterruptsv();
 if(!NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage){_Z20SetIRQInterruptStatei(irq);return 1;}
 switch(*(int*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2260)){
 case 4:_Z20SetIRQInterruptStatei(irq);return 2;
 case 1:_Z20SetIRQInterruptStatei(irq);return 0;
 default:_Z20SetIRQInterruptStatei(irq);return 1;
 case 3:break;
 }
 switch(WM_PowerOff((void*)Network_HandleWirelessLifecycleCommandResult)){
 case 2:Network_SetWirelessStateAndConnectionAlarm(4);*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2280)=2;break;
 case 8:_Z20SetIRQInterruptStatei(irq);return 4;
 case 3:default:Network_SetWirelessStateAndConnectionAlarm(11);_Z20SetIRQInterruptStatei(irq);return 7;
 }
 _Z20SetIRQInterruptStatei(irq);return 3;
}
