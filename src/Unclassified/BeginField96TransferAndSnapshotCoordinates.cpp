#include <globaldefs.h>
extern "C" {
    void TouchInput_RequestIPCOperationFour();
    void WaitForGlobalMaskBitsToClear(int);
    void TestFieldBitsAtOffset38(int);
    void WriteGlobalValueUnderIRQProtection(int);
    void TouchInput_ResetTrackingState(void *);
// Original: arm9/main @ 0x020128D8; symbol: func_020128d8; size: 0x60.
    void BeginField96TransferAndSnapshotCoordinates(unsigned char *p){
        p[99]=p[95];
        *(int *)(p+100)=*(int *)(p+64);
        int a=*(int *)(p+48);
        if(a>=0)*(int *)(p+104)=a;
        int b=*(int *)(p+52);
        if(b>=0)*(int *)(p+108)=b;
        TouchInput_RequestIPCOperationFour();
        WaitForGlobalMaskBitsToClear(4);
        TestFieldBitsAtOffset38(4);
        WriteGlobalValueUnderIRQProtection(0);
        TouchInput_ResetTrackingState(p);
        p[96]=1;
    }
}
