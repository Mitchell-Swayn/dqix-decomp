#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void MenuRecord_ResetHeader(void*);struct Flags{char pad[0x44];unsigned char low:4;unsigned char high:4;unsigned char bit0:1;unsigned char six:6;unsigned char bit7:1;};
// Original: arm9/ov023 @ 0x021F89F4; symbol: InitializeTypeEightMotionRecordWithPackedModes; size: 0xF4.
extern "C" int MenuTextLabel_InitializeSelectableTextRecord(char* self,void* unused,int a,int b,int c,int d,int e,int f,int g,unsigned low,unsigned high){MenuRecord_ResetHeader(self);H(self,4)=8;H(self,6)=a;H(self,8)=b;H(self,10)=0;W(self,16)=0;W(self,28)=2;((Flags*)self)->six=0;H(self,66)=0;((Flags*)self)->bit7=0;W(self,32)=0;W(self,36)=-65536;W(self,40)=-12288;W(self,44)=0;H(self,48)=0;H(self,50)=0;H(self,52)=c;H(self,54)=d;H(self,56)=e;H(self,58)=f;H(self,60)=g;((Flags*)self)->low=(unsigned char)low;((Flags*)self)->high=(unsigned char)high;((Flags*)self)->bit0=0;H(self,70)=0;H(self,72)=0;H(self,74)=0;H(self,76)=0;return 1;}
