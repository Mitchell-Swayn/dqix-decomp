#include <globaldefs.h>
extern "C" void InitializeThirtyTwoRecordsAndOwnerCounters(void*),ClearThirtyTwoByteRecordAndResetHalfwordSentinel(void*);extern "C" void __cxa_vec_cleanup(void*,unsigned,unsigned,void(*)(void*));
// Original: arm9/main @ 0x0203C75C; symbol: func_0203c75c; size: 0x38.
extern "C" ARM char* CleanupThirtyTwoFortyByteRecords(char* p){InitializeThirtyTwoRecordsAndOwnerCounters(p+16);InitializeThirtyTwoRecordsAndOwnerCounters(p+16);__cxa_vec_cleanup(p+20,32,40,ClearThirtyTwoByteRecordAndResetHalfwordSentinel);return p;}
