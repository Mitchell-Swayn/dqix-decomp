#include <globaldefs.h>
struct OffsetBuffer { unsigned reserved[3]; char* base; };
// Original: arm9/main @ 0x02096F80; symbol: func_02096f80; size: 0x30.
extern "C" ARM char* BestiaryInfo_ResolveStringOffset(OffsetBuffer* object, char* address, char* fallback) { bool invalid=true; int offset=address-(char*)0; if(offset!=-1 && object->base) invalid=false; if(!invalid) fallback=object->base+offset; return fallback; }
