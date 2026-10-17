// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x02082FA8; symbol: func_02082fa8; size: 0x1C.
extern "C" void Object_CopyElement0ToElement0AndCopyElement1ToElement1AndCopyElement2ToElement2(int* out,int* in){out[0]=in[0];out[1]=in[1];out[2]=in[2];}
