#include <globaldefs.h>
ARM
extern "C" {extern char* data_ov031_0224e53c;int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);}
// Original: arm9/ov031 @ 0x0220D570; symbol: func_ov031_0220d570; size: 0x9C.
extern "C" unsigned Network_UpdateGlobalFlagsAtomically(unsigned flags){
int irq=_Z20DisableIRQInterruptsv();
char* p=data_ov031_0224e53c;unsigned mask=0;unsigned previous=*(unsigned*)(p+0x2264);
if(!p){_Z20SetIRQInterruptStatei(irq);return 0;}
if(flags&0x8000){mask|=0x3ffe;if(!(flags&0x3ffe))flags|=0xa082;}
if(flags&0x20000)mask|=0x10000;
if(flags&0x80000)mask|=0x40000;
if(flags&0x200000)mask|=0x100000;
if(flags&0x800000)mask|=0x400000;
*(unsigned*)(p+0x2264)=flags|(previous&~mask);
_Z20SetIRQInterruptStatei(irq);return previous;
}
