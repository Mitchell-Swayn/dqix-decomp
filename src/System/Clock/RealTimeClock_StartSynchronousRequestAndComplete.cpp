#include <globaldefs.h>
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int IPC_SetFourArgumentRequestWhenNotBusy(unsigned,unsigned,void(*)(),int);extern "C" void IPC_StoreGlobalReplyValue();extern "C" void RealTimeClock_WaitForRequestCompletion();extern "C" unsigned RTCGetDate_UnknownRoleZeroInitializedStorage[12];
// Original: arm9/main @ 0x020CF25C; symbol: func_020cf25c; size: 0x38.
extern "C" ARM unsigned RealTimeClock_StartSynchronousRequestAndComplete(unsigned a,unsigned b){int status=IPC_SetFourArgumentRequestWhenNotBusy(a,b,IPC_StoreGlobalReplyValue,0);RTCGetDate_UnknownRoleZeroInitializedStorage[11]=status;if(!status)RealTimeClock_WaitForRequestCompletion();return RTCGetDate_UnknownRoleZeroInitializedStorage[11];}
