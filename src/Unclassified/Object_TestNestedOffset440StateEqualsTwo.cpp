// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x0205CD6C; symbol: func_0205cd6c; size: 0x28.
extern "C" int Object_TestNestedOffset440StateEqualsTwo(char* p){char* q=*(char**)(p+0x440);if(!q)return 0;return *(int*)(q+8)==2;}
