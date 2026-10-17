#include <globaldefs.h>
extern "C" int IPC_SetFourArgumentRequestWhenNotBusy(unsigned,unsigned,void(*)(),int);extern "C" void IPC_StoreGlobalReplyValue();extern "C" void func_020cf864();extern "C" unsigned data_02111818[12];
// Original: arm9/main @ 0x020CF25C; symbol: func_020cf25c; size: 0x38.
extern "C" ARM unsigned RealTimeClock_StartSynchronousRequestAndComplete(unsigned a,unsigned b){int status=IPC_SetFourArgumentRequestWhenNotBusy(a,b,IPC_StoreGlobalReplyValue,0);data_02111818[11]=status;if(!status)func_020cf864();return data_02111818[11];}
