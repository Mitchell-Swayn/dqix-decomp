#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov025 @ 0x021ED124; symbol: ClearEightBuffersAndResetSelectionCounters.
extern "C" void Combat_ResetActionMessageQueue(char* self){
H(self,0x15e)=0;H(self,0x1ae)=0;H(self,0x160)=0;W(self,0x158)=0;B(self,0x150)=0;B(self,0x151)=0;memset(self,0,32);memset(self+32,0,32);memset(self+96,0,32);memset(self+160,0,16);memset(self+176,0,64);memset(self+64,0,32);memset(self+240,0,64);memset(self+304,0,16);H(self,0x152)=0;H(self,0x154)=0;B(self,0x16c)=0;H(self,0x1ac)=0;H(self,0x162)=750;H(self,0x15c)=0;
}
