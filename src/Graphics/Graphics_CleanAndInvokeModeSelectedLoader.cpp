#include <globaldefs.h>
ARM
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);typedef void (*Loader)(const void*,unsigned,unsigned);extern "C" Loader data_020e92a8[];struct Load{unsigned mode;const void* source;unsigned offset,size;};
// Original: arm9/main @ 0x020BBC38; symbol: func_020bbc38; size: 0x30.
extern "C" void Graphics_CleanAndInvokeModeSelectedLoader(Load* p){Loader fn=data_020e92a8[p->mode];_Z25CleanInvalidateCacheRangePKvj(p->source,p->size);fn(p->source,p->offset,p->size);}
