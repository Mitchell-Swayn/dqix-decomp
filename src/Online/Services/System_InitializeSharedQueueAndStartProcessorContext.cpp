#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2291f80; symbol: data_ov031_02291f80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemSendOverlayWakeMessage_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224c954; symbol: data_ov031_0224c954.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffff00000000000030000000030000000000000000000000000000000000000000000000000000000000.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2291f60; symbol: data_ov031_02291f60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/ov031 @ 0x2291f44; symbol: data_ov031_02291f44.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemInitializeSharedQueueAndStartProcessorContext_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2291f24; symbol: data_ov031_02291f24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2292040; symbol: data_ov031_02292040.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1216 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov032 @ 0x2292500; symbol: data_ov032_02292500.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64640 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov032.md.
extern "C" unsigned char SystemInitializeSharedQueueAndStartProcessorContext_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void Wireless_RunConnectionWorker();
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void OS_InitMessageQueue(int*,int,int);
extern "C" void MIi_CpuClearFast(int,void*,unsigned);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void*,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x0224587C; symbol: func_ov031_0224587c; size: 0xBC.
extern "C" void System_InitializeSharedQueueAndStartProcessorContext(unsigned value) {
 if(*(unsigned*)(SystemSendOverlayWakeMessage_UnknownRoleZeroInitializedStorage+0x6c)==0 || _Z17IsContextInactiveP16ProcessorContext(SystemSendOverlayWakeMessage_UnknownRoleZeroInitializedStorage)) {
  SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes[1]=value;
  OS_InitMessageQueue(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2,(int)SystemInitializeSharedQueueAndStartProcessorContext_UnknownRoleZeroInitializedStorage,3);
  WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[7]=0;
  WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[6]=0;
  MIi_CpuClearFast(0,WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant3,0xc0);
  _Z24PopulateProcessorContextP16ProcessorContextjjjjj(SystemSendOverlayWakeMessage_UnknownRoleZeroInitializedStorage,(unsigned)Wireless_RunConnectionWorker,0,(unsigned)SystemInitializeSharedQueueAndStartProcessorContext_UnknownRoleZeroInitializedStorage_Variant2,0x400,24);
  WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[1]=0;
  _Z25MarkContextReadyAndSwitchP16ProcessorContext(SystemSendOverlayWakeMessage_UnknownRoleZeroInitializedStorage);
 }
}
