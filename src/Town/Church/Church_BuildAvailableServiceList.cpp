#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original: arm9/ov003 @ 0x0215917C; symbol: BuildSixEntryIndexListFromMask; size: 0xc4.
extern "C" void Church_BuildAvailableServiceList(char* self,unsigned mask) {
 B(self,0x589)=0;
 if(mask&1)B(self+B(self,0x589)++,0x58a)=0;
 if(mask&2)B(self+B(self,0x589)++,0x58a)=1;
 if(mask&4)B(self+B(self,0x589)++,0x58a)=2;
 if(mask&8)B(self+B(self,0x589)++,0x58a)=3;
 if(mask&16)B(self+B(self,0x589)++,0x58a)=4;
 if(mask&32)B(self+B(self,0x589)++,0x58a)=5;
}
