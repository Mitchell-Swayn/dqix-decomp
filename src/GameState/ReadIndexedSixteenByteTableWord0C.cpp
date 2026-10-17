// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x020BD774; symbol: func_020bd774; size: 0x28.
extern "C" unsigned int ReadIndexedSixteenByteTableWord0C(unsigned int i){char* owner=data_02110370[0];char* table=*(char**)(owner+0x84);if(i>=*(unsigned int*)(table+8))return 0;return *(unsigned int*)(table+i*16+12);}
