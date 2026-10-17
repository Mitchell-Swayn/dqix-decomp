// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x02089124; symbol: func_02089124; size: 0x20.
extern "C" void Object_SetByte79ToFiveAndFlag400(char* p){p[0x79]=5;p[0x9c]=0;*(unsigned int*)(p+24)|=0x400;}
