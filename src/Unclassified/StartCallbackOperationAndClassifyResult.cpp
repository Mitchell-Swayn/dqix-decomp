#include <globaldefs.h>
ARM
extern unsigned data_021015a0[];extern "C" void PollCallbackOrFinalizeWhenOwnerFlagged();extern "C" int WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(void(*)());extern "C" void SetGlobalValueExceptModesNineAndTen(int);
// Original: arm9/main @ 0x0202CCA4; symbol: func_0202cca4; size: 0x38.
extern "C" int StartCallbackOperationAndClassifyResult(){data_021015a0[4]=3;int result=WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(PollCallbackOrFinalizeWhenOwnerFlagged);if(result==2)return 1;SetGlobalValueExceptModesNineAndTen(result);return 0;}
