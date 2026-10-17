#include <globaldefs.h>
ARM
extern "C" char* data_ov031_0224e53c;
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" int WirelessCommand_SubmitOpcodeTwentyNineWithFourArguments(void*,unsigned,unsigned,unsigned,unsigned short);
extern "C" void Network_UpdateGlobalFlagsAtomically(int);
extern "C" void func_ov031_0220dc40();
extern "C" void SetSharedStateAndManageStateNineAlarm(int);
// Original: arm9/ov031 @ 0x0220D010; symbol: func_ov031_0220d010; size: 0x204.
extern "C" int Network_StartConfiguredWirelessRequest(const char* config,const unsigned char* options,int mode) {
 int irq=_Z20DisableIRQInterruptsv();
 if(!data_ov031_0224e53c) { _Z20SetIRQInterruptStatei(irq); return 1; }
 switch(*(int*)(data_ov031_0224e53c+0x2260)) {
 case 3:
  if(!config) { _Z20SetIRQInterruptStatei(irq); return 1; }
  if(*(unsigned short*)(config+0x3c)) { _Z20SetIRQInterruptStatei(irq); return 1; }
  if(options) {
   if(options[0]>=4 || options[1]>=4) { _Z20SetIRQInterruptStatei(irq); return 1; }
   *(unsigned char*)(data_ov031_0224e53c+0x2250)=options[0];
   *(unsigned char*)(data_ov031_0224e53c+0x2251)=options[1];
   if(!*(unsigned char*)(data_ov031_0224e53c+0x2250)) VectorizedMemset(data_ov031_0224e53c+0x2200,0,0x50);
   else MI_CpuCopy8(options+2,data_ov031_0224e53c+0x2200,0x50);
  } else VectorizedMemset(data_ov031_0224e53c+0x2200,0,0x52);
  MI_CpuCopy8(config,data_ov031_0224e53c+0x2140,0xc0);
  *(unsigned short*)(data_ov031_0224e53c+0x2170)=*(unsigned short*)(data_ov031_0224e53c+0x216e)|3;
  Network_UpdateGlobalFlagsAtomically(mode);
  break;
 case 8: _Z20SetIRQInterruptStatei(irq); return 2;
 case 9: _Z20SetIRQInterruptStatei(irq); return 0;
 default: _Z20SetIRQInterruptStatei(irq); return 1;
 }
 int result=WirelessCommand_SubmitOpcodeTwentyNineWithFourArguments((void*)func_ov031_0220dc40,0xffff,0x50,0xffff,0xffff);
 switch(result) {
 case 2:
  SetSharedStateAndManageStateNineAlarm(8);
  *(unsigned short*)(data_ov031_0224e53c+0x2280)=5;
  break;
 case 8: _Z20SetIRQInterruptStatei(irq); return 4;
 case 3:
 default: SetSharedStateAndManageStateNineAlarm(11); _Z20SetIRQInterruptStatei(irq); return 7;
 }
 _Z20SetIRQInterruptStatei(irq); return 3;
}
