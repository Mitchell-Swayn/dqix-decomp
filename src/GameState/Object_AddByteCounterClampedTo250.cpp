// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x020A0364; symbol: func_020a0364; size: 0x24.
extern "C" void Object_AddByteCounterClampedTo250(char* p,unsigned int add){ByteCounter* q=(ByteCounter*)(p+8);unsigned int value=q->count+add;if(value>250)value=250;q->count=value;}
