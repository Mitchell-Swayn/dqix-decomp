#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02291f80[];
extern "C" unsigned data_ov031_0224c954[];
extern "C" int data_ov031_02291f60[];
extern "C" unsigned char data_ov031_02291f44[];
extern "C" unsigned data_ov031_02291f24[];
extern "C" unsigned char data_ov031_02292040[];
extern "C" unsigned char data_ov032_02292500[];
extern "C" void func_ov031_0224599c();
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void InitializeEightWordQueueStateWithTwoParameters(int*,int,int);
extern "C" void MIi_CpuClearFast(int,void*,unsigned);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void*,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x0224587C; symbol: func_ov031_0224587c; size: 0xBC.
extern "C" void System_InitializeSharedQueueAndStartProcessorContext(unsigned value) {
 if(*(unsigned*)(data_ov031_02291f80+0x6c)==0 || _Z17IsContextInactiveP16ProcessorContext(data_ov031_02291f80)) {
  data_ov031_0224c954[1]=value;
  InitializeEightWordQueueStateWithTwoParameters(data_ov031_02291f60,(int)data_ov031_02291f44,3);
  data_ov031_02291f24[7]=0;
  data_ov031_02291f24[6]=0;
  MIi_CpuClearFast(0,data_ov031_02292040,0xc0);
  _Z24PopulateProcessorContextP16ProcessorContextjjjjj(data_ov031_02291f80,(unsigned)func_ov031_0224599c,0,(unsigned)data_ov032_02292500,0x400,24);
  data_ov031_02291f24[1]=0;
  _Z25MarkContextReadyAndSwitchP16ProcessorContext(data_ov031_02291f80);
 }
}
