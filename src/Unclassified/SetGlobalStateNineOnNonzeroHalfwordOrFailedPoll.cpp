#include <globaldefs.h>
extern "C" int data_021015a0[];
extern "C" void SetGlobalValueExceptModesNineAndTen(...);
extern "C" int Network_BeginStateThreeOperationUnlessAlreadyActive(void);
// Original: arm9/main @ 0x0202D1E4; symbol: func_0202d1e4; size: 0x40.
extern "C" void SetGlobalStateNineOnNonzeroHalfwordOrFailedPoll(void* object) {
    if (*(unsigned short*)((char*)object+2)!=0) {
        SetGlobalValueExceptModesNineAndTen();
        data_021015a0[4]=9;
        return;
    }
    if (Network_BeginStateThreeOperationUnlessAlreadyActive()==0)
        data_021015a0[4]=9;
}
