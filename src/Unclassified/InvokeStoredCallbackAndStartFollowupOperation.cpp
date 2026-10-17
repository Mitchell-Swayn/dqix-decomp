#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" {
ARM extern unsigned char data_021015a0[],data_02101600[],data_021016e0[]; void SetGlobalStateNineOnNonzeroHalfwordOrFailedPoll(); int ValidateModeZeroThroughThreeAndDispatchCommandTwenty(void(*)(),int,void*); void SetGlobalValueExceptModesNineAndTen(int); struct State { char pad[16]; volatile int value; char gap[28]; int(*callback)(void*,void*); };
// Original: arm9/main @ 0x0202D180; symbol: func_0202d180; size: 0x64.
 int InvokeStoredCallbackAndStartFollowupOperation() { ((State*)data_021015a0)->value=3; int (*callback)(void*,void*)=((State*)data_021015a0)->callback; int result=callback(data_02101600,data_021016e0); result=ValidateModeZeroThroughThreeAndDispatchCommandTwenty(SetGlobalStateNineOnNonzeroHalfwordOrFailedPoll,result,data_02101600); if(result==2)return 1;SetGlobalValueExceptModesNineAndTen(result);((State*)data_021015a0)->value=9;return 0; }
}
