#include <globaldefs.h>
extern "C" void Object_InitializeThirtyTwoByteBufferAndSlotFlagsAndReturnPointer(void*),ClearThirtyTwoByteRecordAndResetHalfwordSentinel(void*),InitializeThirtyTwoRecordsAndOwnerCounters(void*);extern "C" void func_0200ee94(void*,unsigned,unsigned,void(*)(void*),void(*)(void*));
// Original: arm9/main @ 0x0203C2C0; symbol: func_0203c2c0; size: 0x44.
extern "C" ARM char* InitializeThirtyTwoFortyByteRecords(char* p){func_0200ee94(p+4,32,40,Object_InitializeThirtyTwoByteBufferAndSlotFlagsAndReturnPointer,ClearThirtyTwoByteRecordAndResetHalfwordSentinel);InitializeThirtyTwoRecordsAndOwnerCounters(p);return p;}
