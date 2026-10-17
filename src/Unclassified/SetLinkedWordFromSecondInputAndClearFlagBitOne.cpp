// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x02049BAC; symbol: func_02049bac; size: 0x28.
extern "C" void SetLinkedWordFromSecondInputAndClearFlagBitOne(char* p,int* v){char* q=*(char**)(p+0x13c);if(!q)return;*(int*)(q+8)=v[1];q=*(char**)(p+0x13c);*(unsigned int*)(q+32)&=~2u;}
