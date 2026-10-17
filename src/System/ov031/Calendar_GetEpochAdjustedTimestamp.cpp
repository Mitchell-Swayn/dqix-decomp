#include <globaldefs.h>
ARM
extern "C" unsigned Calendar_ReadCurrentDateThroughSynchronousReply(unsigned, unsigned, unsigned, unsigned);
extern "C" int StoreOperationResultAndFinalizeSuccess(int);
extern "C" long long Calendar_ConvertDateTimeToSeconds(void*, int*);
// Original: arm9/ov031 @ 0x02207C98; symbol: func_ov031_02207c98; size: 0x38.
extern "C" unsigned Calendar_GetEpochAdjustedTimestamp(unsigned a, unsigned b, unsigned c, unsigned d) {
    int date[4];
    int time[3];
    Calendar_ReadCurrentDateThroughSynchronousReply((unsigned)date, b, c, d);
    StoreOperationResultAndFinalizeSuccess((int)time);
    return (unsigned)Calendar_ConvertDateTimeToSeconds(date, time) + 0x386D4380;
}
