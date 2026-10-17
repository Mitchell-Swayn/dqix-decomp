#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" {
    extern unsigned char data_02111818[];
    int IPC_DispatchCommandEighteen(void *);
// Original: arm9/main @ 0x020CF134; symbol: func_020cf134; size: 0x74.
    int RealTimeClock_StartRequestUnlessBusy(int a,int b,int c){
        int old=DisableIRQInterrupts();
        if(*(int *)(data_02111818+12)){
            SetIRQInterruptState(old);
            return 1;
        }*(int *)(data_02111818+12)=1;
        SetIRQInterruptState(old);
        *(int *)(data_02111818+32)=1;
        *(int *)(data_02111818+36)=0;
        *(int *)(data_02111818+20)=a;
        *(int *)(data_02111818+16)=b;
        *(int *)(data_02111818+28)=c;
        return IPC_DispatchCommandEighteen(data_02111818)?0:3;
    }
}
