#include <globaldefs.h>
#include <System/Memory.h>
#include <System/ProcessorContext.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" void Network_RunYssdCommandWorker();
extern "C" void OS_InitMessageQueue(int*,int,int);
// Original: arm9/ov031 @ 0x0220F400; symbol: func_ov031_0220f400; size: 0xA0.
extern "C" void System_InitializeOverlay31QueuedContext(unsigned char* buffer) {
StoreReadySharedValue_UnknownRoleZeroInitializedStorage=buffer;
VectorizedMemset(buffer,0,0x8f4);
OS_InitMessageQueue((int*)StoreReadySharedValue_UnknownRoleZeroInitializedStorage,(int)(StoreReadySharedValue_UnknownRoleZeroInitializedStorage+0x20),1);
*(int*)(StoreReadySharedValue_UnknownRoleZeroInitializedStorage+0x24)=0;
unsigned char* p=StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
int priority=GetContextPriority(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.activeContext);
PopulateProcessorContext((ProcessorContext*)(p+0x34),(unsigned int)Network_RunYssdCommandWorker,0,(unsigned int)(p+0x8f4),0x800,priority);
MarkContextStackTopUnknownSubspace((ProcessorContext*)(StoreReadySharedValue_UnknownRoleZeroInitializedStorage+0x34),0x80);
}
