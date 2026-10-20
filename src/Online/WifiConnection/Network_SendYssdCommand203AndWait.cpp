#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" int StoreReadySharedValue(void (*)());
extern "C" void YssdCommand_RecordTransferSizeReply();
extern "C" int System_CompareWordToGlobalResult(void*);
extern "C" void YssdCommand_WaitForReplyCompletion();
extern "C" void YssdCommand_ClearReplyHandler();
// Original: arm9/ov031 @ 0x0220FAAC; symbol: SendYssdCommand203AndWait; size: 0x7c.
// Builds a YSSD command 203 packet and waits for shared completion.
extern "C" void Network_SendYssdCommand203AndWait() {
 char buffer[1044]; struct Header {unsigned int a,b,c,d;}; Header *packet=(Header*)buffer;
 packet->a=16; packet->b=0x44535359; packet->c=203; packet->d=*(unsigned int*)(*(char**)(StoreReadySharedValue_UnknownRoleZeroInitializedStorage+0x24)+4);
 if(StoreReadySharedValue(YssdCommand_RecordTransferSizeReply) && System_CompareWordToGlobalResult(buffer)) YssdCommand_WaitForReplyCompletion();
 YssdCommand_ClearReplyHandler();
}
