// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memset(void*,int,unsigned);extern char data_0210f3c0[];}
// Original: arm9/main @ 0x0209B944; symbol: func_0209b944; size: 0x44.
extern "C" char* FindKeyAmongSix76ByteRecords(char* p,int index,int key,int* out){for(int i=0;i<6;++i){char* q=p+i*76;if(key==*(unsigned short*)q){*out=i;return q+4+index*8;}}return 0;}
