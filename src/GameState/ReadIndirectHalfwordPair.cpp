// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x02059C90; symbol: func_02059c90; size: 0x24.
extern "C" void ReadIndirectHalfwordPair(char* p,short* a,short* b){char* q=*(char**)(p+0x84);q=*(char**)(q+0x54);*a=*(unsigned short*)(q+0x28);q=*(char**)(p+0x84);q=*(char**)(q+0x54);*b=*(unsigned short*)(q+0x2a);}
