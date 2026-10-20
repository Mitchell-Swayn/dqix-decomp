#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
extern "C" void MBi_EndCommon(void*);
extern "C" int MBi_IsTaskAvailable(void);
struct QueueTask;
extern "C" void MBi_EndTaskThread(void (*complete)(QueueTask*));
extern "C" void MBi_ResetAfterTaskThreadEnd(void);
extern "C" int MBi_CallReset(void);
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DCC8C; symbol: func_ov027_021dcc8c; size: 0x94.
// Ends the parent communication session and queues its completion callback when needed.
extern "C" int MBi_CommEnd(void)
{
    int result=1;
    int irq=DisableIRQInterrupts();
    volatile unsigned char *context=*(volatile unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8);
    if(!context[0x50d]) MBi_EndCommon(0);
    else if(*(unsigned short*)(context+0x526)==0) {
        *(unsigned*)(*(volatile unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8)+0x5e4)=0;
        *(unsigned short*)(*(volatile unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8)+0x526)=1;
        if(MBi_IsTaskAvailable()) {
            MBi_EndTaskThread((void (*)(QueueTask*))MBi_ResetAfterTaskThreadEnd);
            result=0;
        } else result=MBi_CallReset();
    }
    SetIRQInterruptState(irq);
    return result;
}
