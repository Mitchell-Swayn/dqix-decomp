#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int, int);
extern "C" void SetGlobalIndexedWordAtOffset18(int, int);
extern "C" int* ReadGlobalOperationContextPointerAt4(void);
extern "C" int func_020d40bc(int, ...);
// Original: arm9/main @ 0x020D4E58; symbol: func_020d4e58; size: 0x64.
extern "C" int ValidateStatusZeroAndDispatchCommandThree(int a, int b) {
    int result=TestCurrentStatusAgainstVariadicAllowedValues(1,0);
    if(result==0) {
        SetGlobalIndexedWordAtOffset18(3,a);
        int* state=ReadGlobalOperationContextPointerAt4();
        result=func_020d40bc(3,4,state[0],state[1],state[4],b);
        if(result==0) result=2;
    }
    return result;
}
