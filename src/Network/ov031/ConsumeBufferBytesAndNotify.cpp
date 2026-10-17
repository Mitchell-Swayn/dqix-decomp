#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" {int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);void func_ov031_02201f84(void*,unsigned);}
struct Buffer { char pad[8];unsigned char state;char pad2[0x33];unsigned capacity;char* data;unsigned size; };
// Original: arm9/ov031 @ 0x022035E0; symbol: func_ov031_022035e0; size: 0x90.
extern "C" void ConsumeBufferBytesAndNotify(unsigned bytes,Buffer* p){
int irq=_Z20DisableIRQInterruptsv();
int wasFull=0;
if(p->size==p->capacity){if(bytes!=0)wasFull=1;}
if(bytes>=p->size)p->size=0;
else{char* data=p->data;unsigned size=p->size-bytes;p->size=size;memmove(data,data+bytes,size);}
_Z20SetIRQInterruptStatei(irq);
if(p->state==10||p->state==11)return;
if(p->size==0||wasFull)func_ov031_02201f84(p,0x1b);
}
