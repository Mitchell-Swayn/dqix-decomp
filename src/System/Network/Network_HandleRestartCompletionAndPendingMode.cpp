#include <globaldefs.h>
ARM
extern unsigned char data_021015a0[];extern "C" void SetGlobalValueExceptModesNineAndTen(unsigned);extern "C" int InvokeStoredCallbackAndStartFollowupOperation();extern "C" int Network_BeginStateThreeOperationUnlessAlreadyActive();
// Original: arm9/main @ 0x0202D108; symbol: func_0202d108; size: 0x78.
extern "C" void Network_HandleRestartCompletionAndPendingMode(unsigned short* param){if(param[1]){SetGlobalValueExceptModesNineAndTen(param[1]);return;}*(unsigned*)(data_021015a0+16)=1;if(!*(unsigned short*)(data_021015a0+4))return;*(unsigned short*)(data_021015a0+4)=0;if(*(unsigned*)(data_021015a0+0x30)){if(!InvokeStoredCallbackAndStartFollowupOperation())*(unsigned*)(data_021015a0+16)=9;}else{if(!Network_BeginStateThreeOperationUnlessAlreadyActive())*(unsigned*)(data_021015a0+16)=9;}}
