// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x0208A018; symbol: func_0208a018; size: 0x24.
extern "C" char* GetBoundedSixtyFourByteRecord(char* p,int i){char* data=*(char**)p;if(!data)return 0;if(*(short*)(p+4)<=i)return 0;return data+i*64;}
