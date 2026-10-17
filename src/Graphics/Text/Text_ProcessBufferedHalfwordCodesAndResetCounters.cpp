#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Object{unsigned char pad[0x4c];unsigned short*codes;unsigned pad2;void*a;void*b;unsigned char pad3[0x10];unsigned count,c1,c2,c3;unsigned char pad4[0xc];unsigned start;};extern "C" int IsCopiedHalfwordHighByteFF(Object*,unsigned short*);extern "C" int ClassifyValidatedFF20ThroughFF25Code(Object*,unsigned short*);extern "C" void TextEntry_DecrementReferenceAndResetUnusedEntry(Object*,unsigned short);
// Original: arm9/main @ 0x0206B104; symbol: func_0206b104; size: 0x94.
extern "C" void Text_ProcessBufferedHalfwordCodesAndResetCounters(Object*p){if(!p->a||!p->b)return;if(!p->count)return;unsigned short*code;unsigned i=p->start;while(i<p->count){code=p->codes+i;if(IsCopiedHalfwordHighByteFF(p,code))i+=ClassifyValidatedFF20ThroughFF25Code(p,code);else TextEntry_DecrementReferenceAndResetUnusedEntry(p,*code);++i;}p->count=0;p->c1=0;p->c2=0;p->c3=0;}
