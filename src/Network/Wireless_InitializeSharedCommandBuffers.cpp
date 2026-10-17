#include <globaldefs.h>
ARM
extern "C" void InitializeEightWordQueueStateWithTwoParameters(int*,int,int);
extern "C" int OS_SendMessage(void*,void*,int);
extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void _Z20DMAMemsetSynchronousijjj(int,unsigned,unsigned,unsigned);
extern "C" void _Z37InitializeInterProcessorCommunicationv();
extern "C" void _Z24SetArm9IPCCommandHandleriPFvjjjE(int,void(*)(unsigned,unsigned,unsigned));
extern "C" int _Z29IsIPCCommandHandlerRegisteredi7IPCSide(int,int);
extern "C" void System_ClearSharedHalfword96BitZero();
extern "C" void WirelessCommand_DispatchSharedResponseAndPortEvents(unsigned,unsigned,unsigned);
struct Global { unsigned short initialized,pad; char* shared; };
extern "C" Global data_021142e0;
extern "C" int data_021142e8[],data_02114308[];
struct Buffer { unsigned short type; char bytes[254]; };
extern "C" Buffer data_02114380[];
// Original: arm9/main @ 0x020D3DF8; symbol: func_020d3df8; size: 0x1E4.
extern "C" int Wireless_InitializeSharedCommandBuffers(char* memory,unsigned dma,unsigned size) {
 int irq=_Z20DisableIRQInterruptsv();
 if(data_021142e0.initialized) {_Z20SetIRQInterruptStatei(irq); return 3;}
 if(!memory) {_Z20SetIRQInterruptStatei(irq); return 6;}
 if(dma>3) {_Z20SetIRQInterruptStatei(irq); return 6;}
 if((unsigned)memory&31) {_Z20SetIRQInterruptStatei(irq); return 6;}
 _Z37InitializeInterProcessorCommunicationv();
 if(!_Z29IsIPCCommandHandlerRegisteredi7IPCSide(10,1)) {_Z20SetIRQInterruptStatei(irq);return 4;}
 _Z24InvalidateDataCacheRangePKvj(memory,size);
 _Z20DMAMemsetSynchronousijjj(dma,(unsigned)memory,0,size);
 data_021142e0.shared=memory;
 *(char**)memory=memory+0x200;
 *(char**)(data_021142e0.shared+4)=*(char**)data_021142e0.shared+0x300;
 *(char**)(data_021142e0.shared+12)=*(char**)(data_021142e0.shared+4)+0x800;
 *(char**)(data_021142e0.shared+16)=*(char**)(data_021142e0.shared+12)+0x100;
 System_ClearSharedHalfword96BitZero();
 *(unsigned short*)(data_021142e0.shared+0x14)=dma;
 *(int*)(data_021142e0.shared+0x14c)=0;
 *(unsigned short*)(data_021142e0.shared+0x150)=0;
 for(int i=0;i<16;i++) {
 *(int*)(data_021142e0.shared+0xcc+i*4)=0;
 *(int*)(data_021142e0.shared+0x10c+i*4)=0;
 }
 InitializeEightWordQueueStateWithTwoParameters(data_021142e8,(int)data_02114308,10);
 for(int i=0;i<10;i++) {
 data_02114380[i].type=0x8000;
 _Z15CleanCacheRangePKvj(&data_02114380[i],2);
 OS_SendMessage(data_021142e8,&data_02114380[i],1);
 }
 _Z24SetArm9IPCCommandHandleriPFvjjjE(10,WirelessCommand_DispatchSharedResponseAndPortEvents);
 data_021142e0.initialized=1;
 _Z20SetIRQInterruptStatei(irq);
 return 0;
}
