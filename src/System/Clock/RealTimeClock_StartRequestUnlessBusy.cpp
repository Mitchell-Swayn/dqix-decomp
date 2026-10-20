#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" {
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char RTCGetDate_UnknownRoleZeroInitializedStorage[];
    int IPC_DispatchCommandEighteen(void *);
// Original: arm9/main @ 0x020CF134; symbol: func_020cf134; size: 0x74.
    int RealTimeClock_StartRequestUnlessBusy(int a,int b,int c){
        int old=DisableIRQInterrupts();
        if(*(int *)(RTCGetDate_UnknownRoleZeroInitializedStorage+12)){
            SetIRQInterruptState(old);
            return 1;
        }*(int *)(RTCGetDate_UnknownRoleZeroInitializedStorage+12)=1;
        SetIRQInterruptState(old);
        *(int *)(RTCGetDate_UnknownRoleZeroInitializedStorage+32)=1;
        *(int *)(RTCGetDate_UnknownRoleZeroInitializedStorage+36)=0;
        *(int *)(RTCGetDate_UnknownRoleZeroInitializedStorage+20)=a;
        *(int *)(RTCGetDate_UnknownRoleZeroInitializedStorage+16)=b;
        *(int *)(RTCGetDate_UnknownRoleZeroInitializedStorage+28)=c;
        return IPC_DispatchCommandEighteen(RTCGetDate_UnknownRoleZeroInitializedStorage)?0:3;
    }
}
