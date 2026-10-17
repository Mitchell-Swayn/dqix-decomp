#include <globaldefs.h>
#include "System/ProcessorContext.h"
extern "C" unsigned data_020f280c[],data_020f2800[]; extern "C" unsigned char *ClampValueBetweenTwoReferencedBounds(unsigned *,unsigned *,unsigned *);
// Original: arm9/main @ 0x020D97A8; symbol: func_020d97a8; size: 0x60.
 extern "C" int ProcessorContext_PopulateWithResolvedEntryAndStack(ProcessorContext *p,unsigned base,unsigned size,unsigned arg,unsigned a,unsigned b) { unsigned char *q=ClampValueBetweenTwoReferencedBounds(&arg,data_020f280c,data_020f2800); PopulateProcessorContext(p,a,b,base+size,size,(unsigned)(q+16));return 1; }
