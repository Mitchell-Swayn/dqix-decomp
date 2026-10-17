// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memset(void*,int,unsigned);extern char data_0210f3c0[];}
// Original: arm9/main @ 0x02079FC8; symbol: func_02079fc8; size: 0x4C.
extern "C" char* Object_ClearFourTwelveByteRecordsAndReturnSelf(char* p){memset(p,0,12);memset(p+12,0,12);memset(p+24,0,12);memset(p+36,0,12);return p;}
