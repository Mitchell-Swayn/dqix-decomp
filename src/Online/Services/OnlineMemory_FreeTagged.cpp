#include <globaldefs.h>
ARM

extern "C" void *Memory_GetAllocationHeaderFromPayload(void *);
// Original data: arm9/ov031 @ 0x224e5ac; symbol: data_ov031_0224e5ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int Ov031SetGlobalPair_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02211B98; symbol: OV031_DispatchContextCallback; size: 0x3C.
// Dispatches a payload through the context's registered callback with its allocation metadata.
extern "C" void OnlineMemory_FreeTagged(void *context, void *payload) {
if(!payload)return; unsigned char *h=(unsigned char*)Memory_GetAllocationHeaderFromPayload(payload); void (*f)(void*,void*,void*)=(void(*)(void*,void*,void*))(Ov031SetGlobalPair_UnknownRoleZeroInitializedStorage[0]); f(context,h,(char*)*(void**)(h+4)+0x20);
}
