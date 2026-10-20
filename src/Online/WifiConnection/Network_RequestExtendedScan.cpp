#include <globaldefs.h>
ARM
extern "C" {
int _Z20DisableIRQInterruptsv();
int _Z20SetIRQInterruptStatei(int);
void Network_ConfigureExtendedScanParameters(const void*,const unsigned char*,void*);
void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
int Network_StartExtendedScan(void*,void*);
void Network_SetWirelessStateAndConnectionAlarm(int);
void Network_HandleExtendedScanResult();
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
}
// Original: arm9/ov031 @ 0x0220CDF4; symbol: func_ov031_0220cdf4; size: 0x178.
extern "C" int Network_RequestExtendedScan(const void* address,const unsigned char* name,void* config){
int irq=_Z20DisableIRQInterruptsv();
if(!NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage){_Z20SetIRQInterruptStatei(irq);return 1;}
switch(*(int*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2260)){
case 3:break;
case 5:Network_ConfigureExtendedScanParameters(address,name,config);_Z20SetIRQInterruptStatei(irq);return 2;
case 6:Network_ConfigureExtendedScanParameters(address,name,config);_Z20SetIRQInterruptStatei(irq);return 0;
default:_Z20SetIRQInterruptStatei(irq);return 1;
}
Network_ConfigureExtendedScanParameters(address,name,config);
_Z24InvalidateDataCacheRangePKvj(*(void**)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2288),*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x228c));
(*(unsigned*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2284))++;
switch(Network_StartExtendedScan((void*)Network_HandleExtendedScanResult,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2288)){
case 2:Network_SetWirelessStateAndConnectionAlarm(5);*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2280)=3;break;
case 8:_Z20SetIRQInterruptStatei(irq);return 4;
case 3:default:Network_SetWirelessStateAndConnectionAlarm(11);_Z20SetIRQInterruptStatei(irq);return 7;
}
_Z20SetIRQInterruptStatei(irq);return 3;
}
