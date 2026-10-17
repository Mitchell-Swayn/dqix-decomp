// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x0206528C; symbol: func_0206528c; size: 0x28.
extern "C" char* LinkedList_FindHalfwordKeyViaOffset10(char** p,int key){char* q=*p;while(q){if(*(unsigned short*)q==key)return q;q=*(char**)(q+16);}return 0;}
