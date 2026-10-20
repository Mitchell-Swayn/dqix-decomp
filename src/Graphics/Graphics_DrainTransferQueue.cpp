#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/main @ 0x210cf94; symbol: data_0210cf94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Entry {unsigned type,a,b,size;}; struct Queue{Entry* entries;unsigned reserved;unsigned short head,tail,count,pad;unsigned bytes;};extern "C" Queue GraphicsDrainTransferQueue_UnknownRoleZeroInitializedStorage;extern "C" Entry* Graphics_GetCurrentTransferQueueEntry(Queue*);extern "C" int Graphics_ConsumeTransferQueueEntry(Queue*);extern "C" void Graphics_CleanAndInvokeModeSelectedLoader(Entry*);
// Original: arm9/main @ 0x020BBCB4; symbol: func_020bbcb4; size: 0x60.
extern "C" ARM void Graphics_DrainTransferQueue(){Queue* q=&GraphicsDrainTransferQueue_UnknownRoleZeroInitializedStorage;Entry* e=Graphics_GetCurrentTransferQueueEntry(q);if(!Graphics_ConsumeTransferQueueEntry(q))return;do{Graphics_CleanAndInvokeModeSelectedLoader(e);q->bytes-=e->size;e=Graphics_GetCurrentTransferQueueEntry(q);}while(Graphics_ConsumeTransferQueueEntry(q));}
