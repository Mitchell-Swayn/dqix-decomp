// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x0209BD94; symbol: func_0209bd94; size: 0x34.
extern "C" char* FindThirtyTwoByteRecordByHalfwordKey(char* p,int key){for(int i=0;i<*(int*)(p+0xc0);++i){int off=i*32;if(*(unsigned short*)(p+off)==key)return p+off;}return 0;}
