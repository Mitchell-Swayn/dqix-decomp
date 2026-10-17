#include <globaldefs.h>
extern unsigned data_021015a0[]; extern unsigned char data_02102be0[];
extern "C" int ClearActiveHalfwordsAndCancelStoredId(void*); extern "C" void SetGlobalValueExceptModesNineAndTen(unsigned); extern "C" void DispatchCallbackOrRecordHalfwordError(unsigned short*); extern "C" int WirelessCommand_SubmitOpcodeOne(void (*)(unsigned short*));
#pragma always_inline on
static inline bool start() { int status=WirelessCommand_SubmitOpcodeOne(DispatchCallbackOrRecordHalfwordError); if(status==2)return true; SetGlobalValueExceptModesNineAndTen(status); return false; }
// Original: arm9/main @ 0x0202DD28; symbol: func_0202dd28; size: 0x70.
extern "C" void Network_RestartOperationAndTrackFailure() { if(data_021015a0[4]==5){int status=ClearActiveHalfwordsAndCancelStoredId(data_02102be0); if(status)SetGlobalValueExceptModesNineAndTen(status);} data_021015a0[4]=3; if(!start())data_021015a0[4]=10; }
