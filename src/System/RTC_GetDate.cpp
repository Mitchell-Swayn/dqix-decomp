#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void IPC_StoreGlobalReplyValue(void);
extern "C" int RTC_GetDateAsync(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void RealTimeClock_WaitForRequestCompletion(void);
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int RTCGetDate_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020CF0FC; symbol: func_020cf0fc; size: 0x38.
extern "C" unsigned int RTC_GetDate(unsigned int param_1, unsigned int unused2, unsigned int unused3, unsigned int param_4) {
    int result = RTC_GetDateAsync(param_1, (unsigned int)IPC_StoreGlobalReplyValue, 0, param_4);
    *(unsigned int *)((char *)&RTCGetDate_UnknownRoleZeroInitializedStorage + 0x2c) = (unsigned int)result;
    if (result == 0) RealTimeClock_WaitForRequestCompletion();
    return *(unsigned int *)((char *)&RTCGetDate_UnknownRoleZeroInitializedStorage + 0x2c);
}
