#include <globaldefs.h>
struct Queue{char pad[8];unsigned short current;short reserved;unsigned short count;};extern "C" int VRAMTransferQueue_IsEmpty(Queue*);extern "C" unsigned short Queue_GetNextWrappedIndex(Queue*,unsigned short);
#pragma optimization_level 4
// Original: arm9/main @ 0x020BBC78; symbol: func_020bbc78; size: 0x3C.
extern "C" ARM int Graphics_ConsumeTransferQueueEntry(Queue* p){if(VRAMTransferQueue_IsEmpty(p))return 0;p->current=Queue_GetNextWrappedIndex(p,p->current);--p->count;return 1;}
