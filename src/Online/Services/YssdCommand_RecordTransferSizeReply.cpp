#include <globaldefs.h>
ARM
struct Transfer {int pad[3];unsigned char* buffer;int pad2;unsigned limit,offset;int pad3;int complete;unsigned finalSize;};
struct Owner {int pad[9];Transfer* transfer;};
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Owner* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220FF34; symbol: func_ov031_0220ff34; size: 0x44.
// Command C9 records the received transfer size and marks the shared transfer complete.
extern "C" int YssdCommand_RecordTransferSizeReply(unsigned* packet) {
 switch(packet[2]) {
 case 0xc9:
  StoreReadySharedValue_UnknownRoleZeroInitializedStorage->transfer->finalSize=packet[3];
  StoreReadySharedValue_UnknownRoleZeroInitializedStorage->transfer->complete=1;
  break;
 case 0xca:break;
 }
 return 1;
}
