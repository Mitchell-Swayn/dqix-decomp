// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x020120B8; symbol: func_020120b8; size: 0x1C.
extern "C" unsigned int* GameState_GetField5CDCEntryWithHighBit(char* p,int i){unsigned int* q=(unsigned int*)(p+0x5cdc)+i;unsigned int v=*q;if(!(v>>31))return 0;return q;}
