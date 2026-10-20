#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);void Network_SetWirelessStateAndConnectionAlarm(int);}
// Original: arm9/ov031 @ 0x0220CF6C; symbol: func_ov031_0220cf6c; size: 0xA4.
extern "C" int Network_RequestSharedStateSeven(){
int irq=_Z20DisableIRQInterruptsv();
if(!NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage){_Z20SetIRQInterruptStatei(irq);return 1;}
switch(*(int*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2260)){
case 6:Network_SetWirelessStateAndConnectionAlarm(7);*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2280)=4;break;
case 7:_Z20SetIRQInterruptStatei(irq);return 2;
case 3:_Z20SetIRQInterruptStatei(irq);return 0;
default:_Z20SetIRQInterruptStatei(irq);return 1;
}
_Z20SetIRQInterruptStatei(irq);return 3;
}
