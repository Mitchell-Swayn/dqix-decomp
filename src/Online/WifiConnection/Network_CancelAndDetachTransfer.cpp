#include <globaldefs.h>
struct Queue;
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(Queue*,unsigned*,unsigned);
struct Transfer {int pad[3];unsigned char* buffer;int pad2;unsigned limit,offset;int pad3;int complete;unsigned finalSize;};
struct Owner {int pad[9];Transfer* transfer;};
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Owner* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220F6E0; symbol: func_ov031_0220f6e0; size: 0x48.
// Drains one queued word without blocking, marks transfer word1C, then detaches it.
extern "C" ARM void Network_CancelAndDetachTransfer(){
 unsigned ignored; MessageQueue_ReceiveWithOptionalBlocking((Queue*)StoreReadySharedValue_UnknownRoleZeroInitializedStorage,&ignored,0);
 Transfer* transfer=StoreReadySharedValue_UnknownRoleZeroInitializedStorage->transfer;
 if(!transfer)return;
 transfer->pad3=1;StoreReadySharedValue_UnknownRoleZeroInitializedStorage->transfer=0;
}
