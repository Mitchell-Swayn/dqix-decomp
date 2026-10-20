#include <globaldefs.h>
#include <System/IPC.h>
ARM
int DisableIRQInterrupts(); void SetIRQInterruptState(int);
extern "C" {

struct Sample { unsigned short x,y,valid,other; };
struct State { unsigned int a; void (*callback)(unsigned,unsigned,unsigned); unsigned char pad8[8]; unsigned short index,mode; Sample *samples; unsigned short count; unsigned char pad1a[30]; unsigned short failed,active; };
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern State TPWaitBusy_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020CDAE4; symbol: func_020cdae4; size: 0x100.
void IPC_InitializeSampleBufferAndSendCommand(unsigned command, unsigned mode, Sample *samples,unsigned count) {
    TPWaitBusy_UnknownRoleZeroInitializedStorage.samples=samples;TPWaitBusy_UnknownRoleZeroInitializedStorage.index=0;TPWaitBusy_UnknownRoleZeroInitializedStorage.mode=mode;TPWaitBusy_UnknownRoleZeroInitializedStorage.count=count;
    unsigned i=0;
    if(count>i)do{TPWaitBusy_UnknownRoleZeroInitializedStorage.samples[i].valid=0;i++;}while(i<count);
    int irq=DisableIRQInterrupts();
    unsigned char success;
    if(SendCommandToArm7(6,(mode&255)|0x2000100,false)<0)success=false;
    else if(SendCommandToArm7(6,command|0x1010000,false)<0)success=false;
    else success=true;
    if (!(success & 255)){SetIRQInterruptState(irq);TPWaitBusy_UnknownRoleZeroInitializedStorage.failed|=2;if(TPWaitBusy_UnknownRoleZeroInitializedStorage.callback)TPWaitBusy_UnknownRoleZeroInitializedStorage.callback(1,4,0);return;}
    TPWaitBusy_UnknownRoleZeroInitializedStorage.active|=2;TPWaitBusy_UnknownRoleZeroInitializedStorage.failed&=~2;SetIRQInterruptState(irq);
}
}
