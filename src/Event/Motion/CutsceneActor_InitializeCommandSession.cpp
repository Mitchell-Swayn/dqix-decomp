#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov001 @ 0x02159D9C; symbol: InitializeSessionVectorFieldsAndObjectSlots; size: 0x10C.
extern "C" void CutsceneActor_InitializeCommandSession(char* self){W(self,112)=-1;memset(self+116,0,12);memset(self+128,0,12);memset(self+252,0,12);*(float*)(self+140)=31.0f;memset(self+172,0,12);memset(self+196,0,12);W(self,220)=0;memset(self+184,0,12);memset(self+208,0,12);W(self,224)=0;W(self,8)=0;W(self,12)=0;W(self,16)=0;W(self,20)=0;W(self,24)=0;W(self,28)=0;W(self,32)=0;W(self,36)=0;W(self,40)=0;W(self,44)=0;W(self,48)=0;W(self,52)=0;W(self,56)=0;W(self,60)=0;W(self,64)=0;W(self,68)=0;W(self,72)=0;W(self,76)=0;W(self,80)=0;W(self,84)=0;W(self,88)=0;W(self,92)=0;W(self,96)=0;W(self,100)=0;W(self,104)=0;W(self,96)=0;W(self,144)=4096;}
