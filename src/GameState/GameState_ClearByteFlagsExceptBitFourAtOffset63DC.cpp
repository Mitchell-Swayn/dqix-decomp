// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x02011AF0; symbol: func_02011af0; size: 0x34.
extern "C" void GameState_ClearByteFlagsExceptBitFourAtOffset63DC(unsigned char* p){bool f=(p[0x63dc]&16)!=0;p[0x63dc]=0;if(f)p[0x63dc]|=16;}
