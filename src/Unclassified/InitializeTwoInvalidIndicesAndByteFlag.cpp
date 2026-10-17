// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x020DA2E4; symbol: func_020da2e4; size: 0x18.
extern "C" void InitializeTwoInvalidIndicesAndByteFlag(char* p){*(int*)(p+8)=-1;*(int*)p=-1;p[4]=0;}
