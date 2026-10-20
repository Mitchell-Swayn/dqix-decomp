#include <globaldefs.h>
#include <System/ProcessorContext.h>
extern "C" {
    int Network_GetLastWirelessError();
    int Network_GetConnectionState();
// Original: arm9/main @ 0x0202B284; symbol: func_0202b284; size: 0x6C.
    int WaitForStatusWithTimeoutAndSleep(void *,int expected){
        unsigned int count=0;
        int status;
        while((status=Network_GetConnectionState())!=expected){
            if(Network_GetLastWirelessError()==8)return 3;
            if((unsigned int)(status-9)<=1)return 1;
            if(++count>20000)return 2;
            SleepCurrentContext(1);
        }return 0;
    }
}
