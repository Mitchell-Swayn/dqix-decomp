#include <globaldefs.h>
ARM
extern "C" char* data_ov031_0224e53c;
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void SetSharedStateAndManageStateNineAlarm(int);
extern "C" unsigned short* ReadSharedValueWhenOperationReady();
extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
extern "C" int ResetIPCOperationStateUnderIRQProtection();
extern "C" int WirelessCommand_SubmitOpcodeFourAfterModeValidation(void*);
extern "C" int ValidateStatusTwoAndDispatchCommandSix(void*);
extern "C" int WirelessCommand_SubmitOpcodeOne(void*);
extern "C" void func_ov031_0220dc40();
extern "C" void func_ov031_0220e7b0();
// Original: arm9/ov031 @ 0x0220D330; symbol: func_ov031_0220d330; size: 0x210.
extern "C" int Network_DispatchSharedWirelessStateOperation() {
 int irq=_Z20DisableIRQInterruptsv();
 if(!data_ov031_0224e53c) {_Z20SetIRQInterruptStatei(irq);return 1;}
 switch(*(unsigned*)(data_ov031_0224e53c+0x2260)) {
 case 13:_Z20SetIRQInterruptStatei(irq);return 2;
 case 1:_Z20SetIRQInterruptStatei(irq);return 0;
 case 6:
 SetSharedStateAndManageStateNineAlarm(13);
 *(unsigned short*)(data_ov031_0224e53c+0x2280)=9;
 _Z20SetIRQInterruptStatei(irq);return 3;
 default:_Z20SetIRQInterruptStatei(irq);return 1;
 case 3:case 9:case 12:break;
 }
 if(*(unsigned char*)(data_ov031_0224e53c+0x226b)==1) {
 SetSharedStateAndManageStateNineAlarm(13);
 *(unsigned short*)(data_ov031_0224e53c+0x2280)=9;
 } else {
 unsigned short* shared=ReadSharedValueWhenOperationReady();
 _Z24InvalidateDataCacheRangePKvj(shared,2);
 int result;
 switch(*shared) {
 case 0:
 result=ResetIPCOperationStateUnderIRQProtection();
 if(result==0) {
 SetSharedStateAndManageStateNineAlarm(1);
 *(unsigned short*)(data_ov031_0224e53c+0x2280)=0;
 _Z20SetIRQInterruptStatei(irq);return 0;
 }break;
 case 1:result=WirelessCommand_SubmitOpcodeFourAfterModeValidation((void*)func_ov031_0220dc40);break;
 case 2:result=ValidateStatusTwoAndDispatchCommandSix((void*)func_ov031_0220dc40);break;
 default:
 *(unsigned char*)(data_ov031_0224e53c+0x226b)=1;
 result=WirelessCommand_SubmitOpcodeOne((void*)func_ov031_0220e7b0);break;
 }
 switch(result) {
 case 2:
 SetSharedStateAndManageStateNineAlarm(13);
 *(unsigned short*)(data_ov031_0224e53c+0x2280)=9;
 break;
 case 8:_Z20SetIRQInterruptStatei(irq);return 4;
 case 3:default:
 SetSharedStateAndManageStateNineAlarm(11);
 _Z20SetIRQInterruptStatei(irq);return 7;
 }
 }
 _Z20SetIRQInterruptStatei(irq);return 3;
}
