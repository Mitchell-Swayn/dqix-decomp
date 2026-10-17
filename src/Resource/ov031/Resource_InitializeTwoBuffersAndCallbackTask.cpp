#include <globaldefs.h>
ARM
struct State {char buffers[0x800];void* handles[2];void* task;};
extern "C" {extern State* data_ov031_02290d60;void* Memory_AllocateZeroedBlock(unsigned,unsigned);void MIi_CpuClearFast(int,void*,unsigned);void* InitializeSteppedOverlayValues(int,void*,int);void* Unclassified_InvokeHelperWithZeroFifthArgument(int,void(*)(),int,int);void Graphics_FlushAndLoadOAM();}
// Original: arm9/ov031 @ 0x0223D928; symbol: func_ov031_0223d928; size: 0x9C.
extern "C" void Resource_InitializeTwoBuffersAndCallbackTask(){
data_ov031_02290d60=(State*)Memory_AllocateZeroedBlock(0x80c,4);
MIi_CpuClearFast(0x200,data_ov031_02290d60,0x800);
int i=0;int offset=0;
do{void* handle=InitializeSteppedOverlayValues(64,data_ov031_02290d60->buffers+offset,8);offset+=0x400;data_ov031_02290d60->handles[i]=handle;i++;}while(i<2);
void* task=Unclassified_InvokeHelperWithZeroFifthArgument(1,Graphics_FlushAndLoadOAM,0,200);data_ov031_02290d60->task=task;
}
