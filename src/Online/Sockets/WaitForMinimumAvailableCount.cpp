#include <globaldefs.h>
ARM
extern "C" {int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);void _Z19BlockCurrentContextP18BlockedContextList(void*);int Network_GetSocketSendBufferFreeBytes(void*);}
// Original: arm9/ov031 @ 0x02206368; symbol: WaitForMinimumAvailableCount; size: 0x84.
// Waits on blocked-context list until minimum availability, clamps maximum and returns associated halfword.
extern "C" int WaitForMinimumAvailableCount(char* p,int maximum,int minimum,unsigned* out,int flags) {char* inner=*(char**)(p+0x68);if(minimum>maximum)minimum=maximum;int irq=_Z20DisableIRQInterruptsv();int count;int block=flags&1;for(;;){count=Network_GetSocketSendBufferFreeBytes(p);if(count>=minimum){*out=*(unsigned short*)(inner+0x100);if(count>=maximum)count=maximum;break;}if(!block){count=0;break;}_Z19BlockCurrentContextP18BlockedContextList(inner+0x104);}_Z20SetIRQInterruptStatei(irq);return count;}
