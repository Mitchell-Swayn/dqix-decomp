// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x0206F0F8; symbol: func_0206f0f8; size: 0x18.
extern "C" unsigned int ComputeTwentyEightByteRecordOffset(struct Flags* p){return p->value*28;}
