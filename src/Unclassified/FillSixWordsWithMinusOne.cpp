// ARM control flow, field widths and constants reviewed.
struct Mode{unsigned int low:23;unsigned int mode:3;unsigned int high:6;};struct Nibble{unsigned char low:4;unsigned char high:4;};struct Field{unsigned short low:9;unsigned short mode:3;unsigned short high:4;};struct Low{unsigned int flag:1;unsigned int rest:31;};struct Bit5{unsigned int low:5;unsigned int flag:1;unsigned int rest:26;};extern "C" unsigned int data_021117ec[];extern "C" void* data_020fe9a4[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);void CleanInvalidateCacheRange(void*,unsigned int);
// Original: arm9/main @ 0x020A18D4; symbol: func_020a18d4; size: 0x20.
extern "C" void FillSixWordsWithMinusOne(char* p){for(unsigned int i=0;i<6;++i)p[i]=-1;}
