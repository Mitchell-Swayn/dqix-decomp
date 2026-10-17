#include <globaldefs.h>
#include "System/Cache.h"
typedef void (*Callback)(void*,unsigned,unsigned);extern "C" Callback data_020f2bb0[];struct Obj{unsigned first,length;unsigned char kind;char pad[3];unsigned offset,last;};extern "C" char* Graphics_ReadSelectedBackgroundOrObjectCharacterBase(unsigned*);
// Original: arm9/main @ 0x020E13DC; symbol: func_020e13dc; size: 0x5C.
extern "C" ARM void CleanCacheAndInvokeTypedRangeCallback(Obj* p){char* base=Graphics_ReadSelectedBackgroundOrObjectCharacterBase(&p->offset);if(!base)return;unsigned offset=p->offset;Callback callback=data_020f2bb0[p->kind];if(!callback)return;CleanInvalidateCacheRange(base+offset,p->length);callback(base+offset,p->first,p->last);CleanCacheRange(base+offset,p->length);}
