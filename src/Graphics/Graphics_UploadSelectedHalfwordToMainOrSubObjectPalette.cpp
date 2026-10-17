#include <globaldefs.h>
#pragma opt_propagation off
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
struct Owner{char pad[62];unsigned char sub;};struct State{unsigned reserved;Owner*owner;char pad[26];unsigned short palette[2];};
// Original: arm9/main @ 0x020E1674; symbol: func_020e1674; size: 0x68.
extern "C" ARM void Graphics_UploadSelectedHalfwordToMainOrSubObjectPalette(State*p,int index,int slot){if(slot<0)return;if(slot>=2)return;int scaled=index*2;void*data=p->palette+slot;CleanInvalidateCacheRange(data,2);unsigned offset=scaled+448;if(p->owner->sub==0)LoadToMainObjStandardPalette(data,offset,2);else LoadToSubObjStandardPalette(data,offset,2);CleanCacheRange(data,2);}
