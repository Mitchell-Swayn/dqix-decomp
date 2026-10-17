// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x020457E8; symbol: func_020457e8; size: 0x3C.
extern "C" void Object_AppendWordToFourEntryRing(char* p,int v){*(int*)(p+0x186c+p[0x19ad]*4)=v;++p[0x19ad];p[0x19ad]=p[0x19ad]%4;}
