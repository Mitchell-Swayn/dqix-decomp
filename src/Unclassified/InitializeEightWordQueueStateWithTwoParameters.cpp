// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x020C7DE4; symbol: func_020c7de4; size: 0x28.
extern "C" void InitializeEightWordQueueStateWithTwoParameters(int* p,int a,int b){p[1]=0;p[0]=0;p[3]=0;p[2]=0;p[4]=a;p[5]=b;p[6]=0;p[7]=0;}
