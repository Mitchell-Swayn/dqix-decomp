#include <globaldefs.h>
#include "System/Cache.h"
// Original data: arm9/main @ 0x20f2bb0; symbol: data_020f2bb0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00000000d85d0c02985e0c02585f0c0218600c02285a0c02385e0c02f85e0c02b85f0c0278600c02805a0c02.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
typedef void (*Callback)(void*,unsigned,unsigned);extern "C" Callback CleanCacheAndInvokeTypedRangeCallback_UnknownRoleProcedureReferenceRecords[];struct Obj{unsigned first,length;unsigned char kind;char pad[3];unsigned offset,last;};extern "C" char* Graphics_ReadSelectedBackgroundOrObjectCharacterBase(unsigned*);
// Original: arm9/main @ 0x020E13DC; symbol: func_020e13dc; size: 0x5C.
extern "C" ARM void CleanCacheAndInvokeTypedRangeCallback(Obj* p){char* base=Graphics_ReadSelectedBackgroundOrObjectCharacterBase(&p->offset);if(!base)return;unsigned offset=p->offset;Callback callback=CleanCacheAndInvokeTypedRangeCallback_UnknownRoleProcedureReferenceRecords[p->kind];if(!callback)return;CleanInvalidateCacheRange(base+offset,p->length);callback(base+offset,p->first,p->last);CleanCacheRange(base+offset,p->length);}
