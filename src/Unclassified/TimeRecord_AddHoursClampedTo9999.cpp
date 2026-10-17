// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x020AC614; symbol: func_020ac614; size: 0x30.
extern "C" void TimeRecord_AddHoursClampedTo9999(unsigned short* p,int add){p[0]+=add;if(p[0]>9999){p[0]=9999;((char*)p)[2]=59;((char*)p)[3]=59;}}
