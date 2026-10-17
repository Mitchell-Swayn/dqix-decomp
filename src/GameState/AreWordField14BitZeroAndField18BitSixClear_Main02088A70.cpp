// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x02088A70; symbol: func_02088a70; size: 0x24.
extern "C" int AreWordField14BitZeroAndField18BitSixClear_Main02088A70(char* p){if(*(unsigned int*)(p+20)&1)return 0;return !(*(unsigned int*)(p+24)&64);}
