#include <globaldefs.h>
ARM
extern "C" int RealTimeClock_StartRequestUnlessBusy(int,void(*)(),int);extern "C" void IPC_StoreGlobalReplyValue();extern "C" void func_020cf864();
struct State{char pad[44];int value;};extern "C" State data_02111818;
// Original: arm9/main @ 0x020CF1A8; symbol: func_020cf1a8; size: 0x38.
extern "C" int StoreOperationResultAndFinalizeSuccess(int a){int r=RealTimeClock_StartRequestUnlessBusy(a,IPC_StoreGlobalReplyValue,0);data_02111818.value=r;if(!r)func_020cf864();return data_02111818.value;}
