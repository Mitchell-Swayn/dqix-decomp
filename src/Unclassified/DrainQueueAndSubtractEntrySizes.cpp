#include <globaldefs.h>
#pragma optimize_for_size off
struct Entry {unsigned type,a,b,size;}; struct Queue{Entry* entries;unsigned reserved;unsigned short head,tail,count,pad;unsigned bytes;};extern "C" Queue data_0210cf94;extern "C" Entry* TestNestedFieldAtOffset8(Queue*);extern "C" int Queue_AdvanceCurrentAndDecrementCount(Queue*);extern "C" void Graphics_CleanAndInvokeModeSelectedLoader(Entry*);
// Original: arm9/main @ 0x020BBCB4; symbol: func_020bbcb4; size: 0x60.
extern "C" ARM void DrainQueueAndSubtractEntrySizes(){Queue* q=&data_0210cf94;Entry* e=TestNestedFieldAtOffset8(q);if(!Queue_AdvanceCurrentAndDecrementCount(q))return;do{Graphics_CleanAndInvokeModeSelectedLoader(e);q->bytes-=e->size;e=TestNestedFieldAtOffset8(q);}while(Queue_AdvanceCurrentAndDecrementCount(q));}
