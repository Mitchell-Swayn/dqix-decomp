#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" void Network_AppendCommandCFTransferChunk();
extern "C" int StoreReadySharedValue(void*);
extern "C" int System_CompareWordToGlobalResult(const unsigned*);
extern "C" void YssdCommand_WaitForReplyCompletion();
extern "C" void YssdCommand_ClearReplyHandler();
// Original: arm9/ov031 @ 0x0220F814; symbol: System_SendSharedConfigurationPacketAndReset; size: 0x94.
// Builds 24-byte packet with YSSD signature and shared configuration fields, waits on ready result and resets state.
extern "C" void System_SendSharedConfigurationPacketAndReset() {
 struct Packet {unsigned size,signature,command,a,b,c;char rest[0x3fc];};unsigned char buffer[0x414];Packet* packet=(Packet*)buffer;packet->size=24;packet->signature=0x44535359;packet->command=0xdb;
 packet->a=*(unsigned*)(*(char**)(StoreReadySharedValue_UnknownRoleZeroInitializedStorage+0x24)+4);
 packet->b=*(unsigned*)(*(char**)(StoreReadySharedValue_UnknownRoleZeroInitializedStorage+0x24)+0x10);
 packet->c=*(unsigned*)(*(char**)(StoreReadySharedValue_UnknownRoleZeroInitializedStorage+0x24)+0x14);
 if(StoreReadySharedValue((void*)Network_AppendCommandCFTransferChunk) && System_CompareWordToGlobalResult((unsigned*)buffer))YssdCommand_WaitForReplyCompletion();
 YssdCommand_ClearReplyHandler();
}
