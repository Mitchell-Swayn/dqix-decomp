#include <globaldefs.h>
extern "C" void *memcpy(void *,const void *,unsigned); struct Header { unsigned count:12; unsigned rest:19; unsigned owned:1; unsigned char *first,*second; };
// Original: arm9/main @ 0x0209A088; symbol: func_0209a088; size: 0x6C.
 extern "C" void InitializeHeaderPointersAndSharedOwnershipFlags(Header *dst,Header *src) { if(!src) return; memcpy(dst,src,4); dst->first=(unsigned char *)src+4;dst->second=(unsigned char *)src+(dst->count*44+4); if(dst->owned) return;dst->owned=1;src->owned=1; }
