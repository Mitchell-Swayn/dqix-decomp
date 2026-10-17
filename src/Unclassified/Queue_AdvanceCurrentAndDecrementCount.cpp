#include <globaldefs.h>
struct Queue{char pad[8];unsigned short current;short reserved;unsigned short count;};extern "C" int Object_TestElement6Equals0(Queue*);extern "C" unsigned short AdvanceWrappedBufferIndex(Queue*,unsigned short);
#pragma optimization_level 4
// Original: arm9/main @ 0x020BBC78; symbol: func_020bbc78; size: 0x3C.
extern "C" ARM int Queue_AdvanceCurrentAndDecrementCount(Queue* p){if(Object_TestElement6Equals0(p))return 0;p->current=AdvanceWrappedBufferIndex(p,p->current);--p->count;return 1;}
