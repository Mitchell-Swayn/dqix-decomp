#include <globaldefs.h>
ARM
extern "C" long long Calendar_ConvertDateTimeToSeconds(void*,int*);
extern "C" int RealTimeClock_ConvertClampedSecondsToDateAndTime(...);
extern "C" int RealTimeClock_StartSynchronousRequestAndComplete(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov031 @ 0x224e688; symbol: data_ov031_0224e688.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224e68c; symbol: data_ov031_0224e68c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/ov031 @ 0x224e694; symbol: data_ov031_0224e694.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage_Variant3[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0221244C; symbol: ValidateRtcSecondsWindowAndConvertDateTime.
extern "C" int OnlineClock_GetAdjustedDateTime(void* date,int* time){
if(!W(OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage,0))return 0;if(RealTimeClock_StartSynchronousRequestAndComplete(date,time))return 0;long long seconds=Calendar_ConvertDateTimeToSeconds(date,time);if(seconds==-1)return 0;if(seconds<*(long long*)OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage_Variant2)seconds+=0xbc191380ULL;long long delta=seconds-*(long long*)OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage_Variant3;if(delta<0||delta>0xbc19137fLL)return 0;RealTimeClock_ConvertClampedSecondsToDateAndTime(date,time,delta);return 1;
}
