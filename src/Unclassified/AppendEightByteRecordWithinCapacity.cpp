// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memset(void*,int,unsigned);extern char data_0210f3c0[];}
// Original: arm9/main @ 0x02072A28; symbol: func_02072a28; size: 0x40.
extern "C" void AppendEightByteRecordWithinCapacity(char* p,char* in){short i=*(short*)(p+6);if(*(short*)(p+4)<=i)return;char* q=*(char**)p+i*8;*(short*)q=*(short*)in;*(int*)(q+4)=*(int*)(in+4);++*(short*)(p+6);}
