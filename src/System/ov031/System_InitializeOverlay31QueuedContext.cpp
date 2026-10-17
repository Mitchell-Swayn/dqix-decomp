#include <globaldefs.h>
#include <System/Memory.h>
#include <System/ProcessorContext.h>
ARM
extern "C" unsigned char* data_ov031_0224e580;
extern "C" void func_ov031_0220f5b4();
extern "C" void InitializeEightWordQueueStateWithTwoParameters(int*,int,int);
// Original: arm9/ov031 @ 0x0220F400; symbol: func_ov031_0220f400; size: 0xA0.
extern "C" void System_InitializeOverlay31QueuedContext(unsigned char* buffer) {
data_ov031_0224e580=buffer;
VectorizedMemset(buffer,0,0x8f4);
InitializeEightWordQueueStateWithTwoParameters((int*)data_ov031_0224e580,(int)(data_ov031_0224e580+0x20),1);
*(int*)(data_ov031_0224e580+0x24)=0;
unsigned char* p=data_ov031_0224e580;
int priority=GetContextPriority(data_02111304.activeContext);
PopulateProcessorContext((ProcessorContext*)(p+0x34),(unsigned int)func_ov031_0220f5b4,0,(unsigned int)(p+0x8f4),0x800,priority);
MarkContextStackTopUnknownSubspace((ProcessorContext*)(data_ov031_0224e580+0x34),0x80);
}
