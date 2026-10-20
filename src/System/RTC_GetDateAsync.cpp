#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned RTCGetDate_UnknownRoleZeroInitializedStorage[];extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" int RealTimeClock_SendReadDateRequest();
// Original: arm9/main @ 0x020CF08C; symbol: func_020cf08c; size: 0x70.
extern "C" int RTC_GetDateAsync(unsigned a0,unsigned a1,unsigned a2){int irq=_Z20DisableIRQInterruptsv();if(RTCGetDate_UnknownRoleZeroInitializedStorage[3]){_Z20SetIRQInterruptStatei(irq);return 1;}RTCGetDate_UnknownRoleZeroInitializedStorage[3]=1;_Z20SetIRQInterruptStatei(irq);RTCGetDate_UnknownRoleZeroInitializedStorage[8]=0;RTCGetDate_UnknownRoleZeroInitializedStorage[9]=0;RTCGetDate_UnknownRoleZeroInitializedStorage[5]=a0;RTCGetDate_UnknownRoleZeroInitializedStorage[4]=a1;RTCGetDate_UnknownRoleZeroInitializedStorage[7]=a2;return RealTimeClock_SendReadDateRequest()?0:3;}
