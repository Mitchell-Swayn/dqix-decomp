#include <globaldefs.h>
#include "System/ProcessorContext.h"
// Original data: arm9/main @ 0x20f2800; symbol: data_020f2800.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0f000000f1ffffff0f000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f280c; symbol: data_020f280c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex f1ffffff.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned ProcessorContextPopulateWithResolvedEntryAndStack_UnknownRoleInitializedBytes_Variant2[],ProcessorContextPopulateWithResolvedEntryAndStack_UnknownRoleInitializedBytes[]; extern "C" unsigned char *ProcessorContext_ClampRequestedPriority(unsigned *,unsigned *,unsigned *);
// Original: arm9/main @ 0x020D97A8; symbol: func_020d97a8; size: 0x60.
 extern "C" int ProcessorContext_PopulateWithResolvedEntryAndStack(ProcessorContext *p,unsigned base,unsigned size,unsigned arg,unsigned a,unsigned b) { unsigned char *q=ProcessorContext_ClampRequestedPriority(&arg,ProcessorContextPopulateWithResolvedEntryAndStack_UnknownRoleInitializedBytes_Variant2,ProcessorContextPopulateWithResolvedEntryAndStack_UnknownRoleInitializedBytes); PopulateProcessorContext(p,a,b,base+size,size,(unsigned)(q+16));return 1; }
