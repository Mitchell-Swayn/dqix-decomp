#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e92a8; symbol: data_020e92a8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 98b90b02c4b90b02f0b90b0214ba0b0238ba0b0244ba0b0250ba0b025cba0b0268ba0b0274ba0b0280ba0b028cba0b0298ba0b02a4ba0b02b0ba0b02bcba0b02 ...; full span in module reference.
// Observed span: 144 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);typedef void (*Loader)(const void*,unsigned,unsigned);extern "C" Loader GraphicsCleanAndInvokeModeSelectedLoader_UnknownRoleProcedureReferenceRecords[];struct Load{unsigned mode;const void* source;unsigned offset,size;};
// Original: arm9/main @ 0x020BBC38; symbol: func_020bbc38; size: 0x30.
extern "C" void Graphics_CleanAndInvokeModeSelectedLoader(Load* p){Loader fn=GraphicsCleanAndInvokeModeSelectedLoader_UnknownRoleProcedureReferenceRecords[p->mode];_Z25CleanInvalidateCacheRangePKvj(p->source,p->size);fn(p->source,p->offset,p->size);}
