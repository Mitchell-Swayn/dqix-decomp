#include <globaldefs.h>
ARM
extern "C" void OS_InitMessageQueue(int*,int,int);
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
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Global WMiCheckIdle_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x21142e8; symbol: data_021142e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114308; symbol: data_02114308.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int WMiSendCommand_UnknownRoleZeroInitializedStorage[],WirelessInitializeSharedCommandBuffers_UnknownRoleZeroInitializedStorage[];
struct Buffer { unsigned short type; char bytes[254]; };
// Original data: arm9/main @ 0x2114380; symbol: data_02114380.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2560 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Buffer WirelessInitializeSharedCommandBuffers_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/main @ 0x020D3DF8; symbol: func_020d3df8; size: 0x1E4.
extern "C" int Wireless_InitializeSharedCommandBuffers(char* memory,unsigned dma,unsigned size) {
 int irq=_Z20DisableIRQInterruptsv();
 if(WMiCheckIdle_UnknownRoleZeroInitializedStorage.initialized) {_Z20SetIRQInterruptStatei(irq); return 3;}
 if(!memory) {_Z20SetIRQInterruptStatei(irq); return 6;}
 if(dma>3) {_Z20SetIRQInterruptStatei(irq); return 6;}
 if((unsigned)memory&31) {_Z20SetIRQInterruptStatei(irq); return 6;}
 _Z37InitializeInterProcessorCommunicationv();
 if(!_Z29IsIPCCommandHandlerRegisteredi7IPCSide(10,1)) {_Z20SetIRQInterruptStatei(irq);return 4;}
 _Z24InvalidateDataCacheRangePKvj(memory,size);
 _Z20DMAMemsetSynchronousijjj(dma,(unsigned)memory,0,size);
 WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared=memory;
 *(char**)memory=memory+0x200;
 *(char**)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+4)=*(char**)WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+0x300;
 *(char**)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+12)=*(char**)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+4)+0x800;
 *(char**)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+16)=*(char**)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+12)+0x100;
 System_ClearSharedHalfword96BitZero();
 *(unsigned short*)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+0x14)=dma;
 *(int*)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+0x14c)=0;
 *(unsigned short*)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+0x150)=0;
 for(int i=0;i<16;i++) {
 *(int*)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+0xcc+i*4)=0;
 *(int*)(WMiCheckIdle_UnknownRoleZeroInitializedStorage.shared+0x10c+i*4)=0;
 }
 OS_InitMessageQueue(WMiSendCommand_UnknownRoleZeroInitializedStorage,(int)WirelessInitializeSharedCommandBuffers_UnknownRoleZeroInitializedStorage,10);
 for(int i=0;i<10;i++) {
 WirelessInitializeSharedCommandBuffers_UnknownRoleZeroInitializedStorage_Variant2[i].type=0x8000;
 _Z15CleanCacheRangePKvj(&WirelessInitializeSharedCommandBuffers_UnknownRoleZeroInitializedStorage_Variant2[i],2);
 OS_SendMessage(WMiSendCommand_UnknownRoleZeroInitializedStorage,&WirelessInitializeSharedCommandBuffers_UnknownRoleZeroInitializedStorage_Variant2[i],1);
 }
 _Z24SetArm9IPCCommandHandleriPFvjjjE(10,WirelessCommand_DispatchSharedResponseAndPortEvents);
 WMiCheckIdle_UnknownRoleZeroInitializedStorage.initialized=1;
 _Z20SetIRQInterruptStatei(irq);
 return 0;
}
