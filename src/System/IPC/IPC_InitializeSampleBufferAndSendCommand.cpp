#include <globaldefs.h>
#include <System/IPC.h>
ARM
int DisableIRQInterrupts(); void SetIRQInterruptState(int);
extern "C" {

struct Sample { unsigned short x,y,valid,other; };
struct State { unsigned int a; void (*callback)(unsigned,unsigned,unsigned); unsigned char pad8[8]; unsigned short index,mode; Sample *samples; unsigned short count; unsigned char pad1a[30]; unsigned short failed,active; };
extern State data_021117b0;
// Original: arm9/main @ 0x020CDAE4; symbol: func_020cdae4; size: 0x100.
void IPC_InitializeSampleBufferAndSendCommand(unsigned command, unsigned mode, Sample *samples,unsigned count) {
    data_021117b0.samples=samples;data_021117b0.index=0;data_021117b0.mode=mode;data_021117b0.count=count;
    unsigned i=0;
    if(count>i)do{data_021117b0.samples[i].valid=0;i++;}while(i<count);
    int irq=DisableIRQInterrupts();
    unsigned char success;
    if(SendCommandToArm7(6,(mode&255)|0x2000100,false)<0)success=false;
    else if(SendCommandToArm7(6,command|0x1010000,false)<0)success=false;
    else success=true;
    if (!(success & 255)){SetIRQInterruptState(irq);data_021117b0.failed|=2;if(data_021117b0.callback)data_021117b0.callback(1,4,0);return;}
    data_021117b0.active|=2;data_021117b0.failed&=~2;SetIRQInterruptState(irq);
}
}
