#include <globaldefs.h>
ARM
struct State{unsigned char pad[0x2c];unsigned char* entries;unsigned char pad30[8];unsigned char count;};extern "C" {void func_0204b088(void*,int);
// Original: arm9/main @ 0x0207FD88; symbol: func_0207fd88; size: 0x44.
void Graphics_ResetCountedTransferEntriesWithModeZero(State* p){int zero;unsigned char count;unsigned char* cur=p->entries;unsigned char i;if(!cur)return;i=0;count=p->count;zero=0;for(;i<count;i++){func_0204b088(cur,zero);cur+=0x20;}}}
