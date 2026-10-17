// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memset(void*,int,unsigned);extern char data_0210f3c0[];}
// Original: arm9/main @ 0x020A0BCC; symbol: func_020a0bcc; size: 0x40.
extern "C" void InitializeParallelKeyAndByteArrays(char* p){short* a=*(short**)p;char* b=*(char**)(p+4);short count=*(short*)(p+8);for(short i=0;i<count;++i){a[i]=-1;b[i]=0;}}
