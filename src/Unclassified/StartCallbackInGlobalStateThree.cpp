#include <globaldefs.h>
ARM
extern "C" unsigned data_021015a0[]; extern "C" void Network_BeginDisconnectOperationAndHandleFailure(); extern "C" int WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(void(*)()); extern "C" void SetGlobalValueExceptModesNineAndTen(int);
// Original: arm9/main @ 0x0202D54C; symbol: func_0202d54c; size: 0x38.
 extern "C" int StartCallbackInGlobalStateThree(){ data_021015a0[4]=3; int r=WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(Network_BeginDisconnectOperationAndHandleFailure); if(r==2)return 1; SetGlobalValueExceptModesNineAndTen(r);return 0;}
