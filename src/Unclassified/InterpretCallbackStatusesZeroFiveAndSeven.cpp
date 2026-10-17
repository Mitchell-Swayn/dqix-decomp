#include <globaldefs.h>
extern "C" int data_02102be0[];
extern "C" int data_02101980[];
extern "C" int Network_ExchangeQueuedWirelessPacket(int, int, int, int);
extern "C" void SetGlobalValueExceptModesNineAndTen(...);
// Original: arm9/main @ 0x0202DCD4; symbol: func_0202dcd4; size: 0x54.
extern "C" int InterpretCallbackStatusesZeroFiveAndSeven(int a, int b, int c, int d) {
    int result=Network_ExchangeQueuedWirelessPacket((int)data_02102be0,a,(int)data_02101980,d);
    if (result==7) return 1;
    if (result==5) {
        SetGlobalValueExceptModesNineAndTen();
        return 0;
    }
    if (result==0) return 1;
    SetGlobalValueExceptModesNineAndTen(result);
    return 0;
}
