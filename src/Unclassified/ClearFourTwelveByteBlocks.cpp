// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memset(void*,int,unsigned);extern char data_0210f3c0[];}
// Original: arm9/main @ 0x020798B8; symbol: func_020798b8; size: 0x48.
extern "C" void ClearFourTwelveByteBlocks(char* p){memset(p,0,12);memset(p+12,0,12);memset(p+24,0,12);memset(p+36,0,12);}
