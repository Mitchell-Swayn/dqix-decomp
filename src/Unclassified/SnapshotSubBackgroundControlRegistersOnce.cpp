#include <globaldefs.h>
struct State { volatile unsigned short a,x,b,y,c,z,d,w; unsigned char unused,initialized; };
// Original: arm9/main @ 0x02074B64; symbol: func_02074b64; size: 0x6C.
 extern "C" void SnapshotSubBackgroundControlRegistersOnce(State* p) { if(p->initialized)return; volatile short local[4]; volatile unsigned* regs=(volatile unsigned*)0x04001008; unsigned short a=*(volatile unsigned short*)((char*)regs+0);local[3]=a;p->x=a;(void)local[3]; unsigned short b=*(volatile unsigned short*)((char*)regs+2);p->y=b;local[2]=b;(void)local[2]; unsigned short c=*(volatile unsigned short*)((char*)regs+4);local[1]=c;(void)local[1];p->z=c;(void)local[1]; unsigned short d=*(volatile unsigned short*)((char*)regs+6);p->w=d;local[0]=d;(void)local[0]; p->initialized=1; }
