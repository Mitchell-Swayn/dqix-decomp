#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"
// Original data: arm9/main @ 0x2112328; symbol: data_02112328.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x211232c; symbol: data_0211232c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1060 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2112750; symbol: data_02112750.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" ProcessorContext* InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage;extern "C" char InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage_Variant2[];extern "C" char InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage_Variant3[];extern "C" void SystemWorker_RunPendingMessagesUntilStopped();extern "C" void SystemWorker_ClearMessage(void*);
// Original: arm9/main @ 0x020D1954; symbol: func_020d1954; size: 0x8C.
extern "C" ARM void InitializeGlobalProcessorContextOnce(ProcessorContext* p){int irq=DisableIRQInterrupts();if(!InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage){InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage=p;SystemWorker_ClearMessage((char*)p+0xc4);SystemWorker_ClearMessage(InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage_Variant2);*(unsigned*)((char*)p+0xc0)=0;PopulateProcessorContext(p,(unsigned)SystemWorker_RunPendingMessagesUntilStopped,(unsigned)p,(unsigned)InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage_Variant3,0x400,20);MarkContextReadyAndSwitch(p);}SetIRQInterruptState(irq);}
