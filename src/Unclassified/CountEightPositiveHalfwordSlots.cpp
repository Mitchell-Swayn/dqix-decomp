// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x02083960; symbol: func_02083960; size: 0x34.
extern "C" int CountEightPositiveHalfwordSlots(char* p){int n=0;for(int i=0;i<8;++i)if(*(short*)(p+i*2+0x454)>0)++n;return n;}
