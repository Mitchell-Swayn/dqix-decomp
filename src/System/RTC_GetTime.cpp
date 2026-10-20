#include <globaldefs.h>
ARM
extern "C" int RealTimeClock_StartRequestUnlessBusy(int,void(*)(),int);extern "C" void IPC_StoreGlobalReplyValue();extern "C" void RealTimeClock_WaitForRequestCompletion();
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{char pad[44];int value;};extern "C" State RTCGetDate_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020CF1A8; symbol: func_020cf1a8; size: 0x38.
extern "C" int RTC_GetTime(int a){int r=RealTimeClock_StartRequestUnlessBusy(a,IPC_StoreGlobalReplyValue,0);RTCGetDate_UnknownRoleZeroInitializedStorage.value=r;if(!r)RealTimeClock_WaitForRequestCompletion();return RTCGetDate_UnknownRoleZeroInitializedStorage.value;}
