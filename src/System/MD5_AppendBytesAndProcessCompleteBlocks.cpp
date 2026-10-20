#include <globaldefs.h>
ARM
struct Eight {short values[8];};struct Triple {int x,y,z;};
extern "C" int MI_CpuCopy8(...);
extern "C" int MD5_CompressBufferedBlock(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/main @ 0x020C0368; symbol: MD5_AppendBytesAndProcessCompleteBlocks; size: 0xc8.
// MD5 AppendBytesAndProcessCompleteBlocks from listed field operations and calls.
extern "C" void MD5_AppendBytesAndProcessCompleteBlocks(char* self,const char* source,unsigned length){unsigned offset=U(self,16)&63;*(unsigned long long*)(self+16)+=length;unsigned available=64-offset;if(available>length){if(length)MI_CpuCopy8(source,self+24+offset,length);return;}MI_CpuCopy8(source,self+24+offset,available);MD5_CompressBufferedBlock(self);length-=available;int blocks=length>>6;const char* next=source+available;if(blocks>0)do{MI_CpuCopy8(next,self+24,64);next+=64;MD5_CompressBufferedBlock(self);--blocks;}while(blocks>0);if(length&63)MI_CpuCopy8(next,self+24,length&63);}
