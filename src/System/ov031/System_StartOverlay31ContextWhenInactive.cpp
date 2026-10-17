#include <globaldefs.h>
#include <System/ProcessorContext.h>
ARM
#pragma optimization_level 4
bool IsContextInactive(ProcessorContext*);
extern "C" unsigned char* data_ov031_0224e60c;
extern "C" void func_ov031_022192c0();
// Original: arm9/ov031 @ 0x02219238; symbol: func_ov031_02219238; size: 0x88.
extern "C" void System_StartOverlay31ContextWhenInactive() {
if(*(unsigned int*)(data_ov031_0224e60c+0x1188) && !IsContextInactive((ProcessorContext*)(data_ov031_0224e60c+0x111c)))return;
PopulateProcessorContext((ProcessorContext*)(data_ov031_0224e60c+0x111c),(unsigned int)func_ov031_022192c0,(unsigned int)data_ov031_0224e60c,(unsigned int)(data_ov031_0224e60c+0x1000),0x1000,16);
MarkContextReadyAndSwitch((ProcessorContext*)(data_ov031_0224e60c+0x111c));
}
