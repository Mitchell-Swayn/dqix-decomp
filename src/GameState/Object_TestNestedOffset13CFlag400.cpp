// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x0204A0F8; symbol: func_0204a0f8; size: 0x28.
extern "C" int Object_TestNestedOffset13CFlag400(char* p){char* q=*(char**)(p+0x13c);if(!q)return 0;return (*(unsigned int*)(q+32)&0x400)!=0;}
