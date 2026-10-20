#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void Network_SetWirelessStateAndConnectionAlarm(int);
extern "C" unsigned short* WMi_GetStatusAddress();
extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
extern "C" int ResetIPCOperationStateUnderIRQProtection();
extern "C" int WirelessCommand_SubmitOpcodeFourAfterModeValidation(void*);
extern "C" int WM_PowerOff(void*);
extern "C" int WirelessCommand_SubmitOpcodeOne(void*);
extern "C" void Network_HandleWirelessLifecycleCommandResult();
extern "C" void Network_HandleWirelessResetResult();
// Original: arm9/ov031 @ 0x0220D330; symbol: func_ov031_0220d330; size: 0x210.
extern "C" int Network_DispatchSharedWirelessStateOperation() {
 int irq=_Z20DisableIRQInterruptsv();
 if(!NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage) {_Z20SetIRQInterruptStatei(irq);return 1;}
 switch(*(unsigned*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2260)) {
 case 13:_Z20SetIRQInterruptStatei(irq);return 2;
 case 1:_Z20SetIRQInterruptStatei(irq);return 0;
 case 6:
 Network_SetWirelessStateAndConnectionAlarm(13);
 *(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2280)=9;
 _Z20SetIRQInterruptStatei(irq);return 3;
 default:_Z20SetIRQInterruptStatei(irq);return 1;
 case 3:case 9:case 12:break;
 }
 if(*(unsigned char*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x226b)==1) {
 Network_SetWirelessStateAndConnectionAlarm(13);
 *(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2280)=9;
 } else {
 unsigned short* shared=WMi_GetStatusAddress();
 _Z24InvalidateDataCacheRangePKvj(shared,2);
 int result;
 switch(*shared) {
 case 0:
 result=ResetIPCOperationStateUnderIRQProtection();
 if(result==0) {
 Network_SetWirelessStateAndConnectionAlarm(1);
 *(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2280)=0;
 _Z20SetIRQInterruptStatei(irq);return 0;
 }break;
 case 1:result=WirelessCommand_SubmitOpcodeFourAfterModeValidation((void*)Network_HandleWirelessLifecycleCommandResult);break;
 case 2:result=WM_PowerOff((void*)Network_HandleWirelessLifecycleCommandResult);break;
 default:
 *(unsigned char*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x226b)=1;
 result=WirelessCommand_SubmitOpcodeOne((void*)Network_HandleWirelessResetResult);break;
 }
 switch(result) {
 case 2:
 Network_SetWirelessStateAndConnectionAlarm(13);
 *(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2280)=9;
 break;
 case 8:_Z20SetIRQInterruptStatei(irq);return 4;
 case 3:default:
 Network_SetWirelessStateAndConnectionAlarm(11);
 _Z20SetIRQInterruptStatei(irq);return 7;
 }
 }
 _Z20SetIRQInterruptStatei(irq);return 3;
}
