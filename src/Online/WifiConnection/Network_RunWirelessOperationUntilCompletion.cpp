#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/ProcessorContext.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" void DisableInterruptsAndHaltForever();
extern "C" int Network_StartWirelessInitializationUnderIRQ(unsigned*,int);
extern "C" int Network_RequestWirelessPowerOff();
extern "C" int Network_RequestExtendedScan(const void*,const unsigned char*,void*);
extern "C" int Network_RequestSharedStateSeven();
extern "C" int Network_StartConfiguredWirelessRequest(const char*,const unsigned char*,int);
extern "C" int Network_RequestDcfDisconnect();
extern "C" int Network_DispatchSharedWirelessStateOperation();
extern "C" void System_DispatchOverlayQueueEvent(short* event);
struct WirelessStatus {unsigned pad[2];volatile unsigned result;unsigned extended;};
struct WirelessConfiguration {unsigned pad;char* address;unsigned scanFlags,requestFlags;};
// Original data: arm9/ov031 @ 0x2291f24; symbol: data_ov031_02291f24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" WirelessStatus WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224c954; symbol: data_ov031_0224c954.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffff00000000000030000000030000000000000000000000000000000000000000000000000000000000.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" WirelessConfiguration SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x2291f3c; symbol: data_ov031_02291f3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2291f50; symbol: data_ov031_02291f50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2292040; symbol: data_ov031_02292040.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1216 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkRunWirelessOperationUntilCompletion_UnknownRoleZeroInitializedStorage[],WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant3[],SystemDispatchOverlayQueueEvent_UnknownRoleZeroInitializedStorage[];
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x02245C68; symbol: func_ov031_02245c68; size: 0x1F4.
// Dispatches wireless operations, retries busy states, blocks pending contexts and halts on terminal failures.
extern "C" int Network_RunWirelessOperationUntilCompletion(unsigned operation){
int result=7;int irq=_Z20DisableIRQInterruptsv();
for(;;){
switch(operation){
case 1:result=Network_StartWirelessInitializationUnderIRQ((unsigned*)NetworkRunWirelessOperationUntilCompletion_UnknownRoleZeroInitializedStorage,(int)System_DispatchOverlayQueueEvent);break;
case 2:result=Network_RequestWirelessPowerOff();break;
case 3:result=Network_RequestExtendedScan(SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes.address,(unsigned char*)SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes.address+88,(void*)((SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes.scanFlags|0xbffe)|(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage.extended?0xc00000:0x800000)));break;
case 4:result=Network_RequestSharedStateSeven();break;
case 5:{char* address=SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes.address;result=Network_StartConfiguredWirelessRequest(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant3,(unsigned char*)address+6,SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes.requestFlags|F(unsigned,address,0x78));break;}
case 6:result=Network_RequestDcfDisconnect();break;
case 9:result=Network_DispatchSharedWirelessStateOperation();break;
case 0:case 7:case 8:default:SetIRQInterruptState(irq);return result;
}
switch(result){
case 4:SleepCurrentContext(1);continue;
case 2:case 3:BlockCurrentContext((BlockedContextList*)SystemDispatchOverlayQueueEvent_UnknownRoleZeroInitializedStorage);break;
case 0:case 1:SetIRQInterruptState(irq);return result;
case 5:DisableInterruptsAndHaltForever();
case 6:case 7:default:SetIRQInterruptState(irq);for(;;)SleepCurrentContext(10000);
}
break;
}
int completion;
switch(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage.result){
case 0:case 1:completion=WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage.result;break;
case 2:case 3:case 4:case 5:case 6:case 7:default:SetIRQInterruptState(irq);for(;;)SleepCurrentContext(10000);
}
SetIRQInterruptState(irq);return completion;
}
