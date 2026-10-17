// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memset(void*,int,unsigned);extern char data_0210f3c0[];}
// Original: arm9/main @ 0x02054EF8; symbol: func_02054ef8; size: 0x44.
extern "C" int Memory_AllocateAndClearThreeWordRecord(void** p,SafeAllocator* a){if(!a)return 0;int* q=(int*)a->Allocate(12);*p=q;if(!q)return 0;q[0]=0;q[1]=0;q[2]=0;return 1;}
