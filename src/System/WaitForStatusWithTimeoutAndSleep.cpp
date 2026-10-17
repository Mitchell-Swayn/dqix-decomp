#include <globaldefs.h>
#include <System/ProcessorContext.h>
extern "C" {
    int ReadGlobalAt021015A0Index18();
    int Object_ReadElement4();
// Original: arm9/main @ 0x0202B284; symbol: func_0202b284; size: 0x6C.
    int WaitForStatusWithTimeoutAndSleep(void *,int expected){
        unsigned int count=0;
        int status;
        while((status=Object_ReadElement4())!=expected){
            if(ReadGlobalAt021015A0Index18()==8)return 3;
            if((unsigned int)(status-9)<=1)return 1;
            if(++count>20000)return 2;
            SleepCurrentContext(1);
        }return 0;
    }
}
