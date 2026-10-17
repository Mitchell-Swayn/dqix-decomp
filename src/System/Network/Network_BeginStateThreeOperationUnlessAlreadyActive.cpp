#include <globaldefs.h>
#pragma optimize_for_size on
extern "C" char data_021015a0[], data_02101614[]; extern "C" unsigned short data_021016e0[]; extern "C" void HandleMessageErrorAndOperationCode(); extern "C" int WirelessCommand_SubmitOpcodeTwelveWithCachedBufferAndPayload(int,unsigned short*,const void*,int,unsigned short);extern "C" void SetGlobalValueExceptModesNineAndTen(int);
// Original: arm9/main @ 0x0202D224; symbol: func_0202d224; size: 0x80.
extern "C" ARM int Network_BeginStateThreeOperationUnlessAlreadyActive(){int state=*(int*)(data_021015a0+16);if(state==4||state==6||*(int*)(data_021015a0+16)==5)return 1;*(int*)(data_021015a0+16)=3;int result=WirelessCommand_SubmitOpcodeTwelveWithCachedBufferAndPayload((int)HandleMessageErrorAndOperationCode,data_021016e0,data_02101614,1,(unsigned short)(int)(*(int*)(data_021015a0+48)!=0));if(result==2)return 1;SetGlobalValueExceptModesNineAndTen(result);return 0;}
