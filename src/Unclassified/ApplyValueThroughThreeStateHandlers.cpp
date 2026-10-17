#include <globaldefs.h>
extern "C" void* ReadGlobalValueAt02108844();extern "C" void InvokeBoundedIndexWithModeThree(void*,int);extern "C" void CountedKeyRecords_RemoveById(void*,int);extern "C" void ApplyBoundedIdAndUpdateRecordState(void*,int);
// Original: arm9/main @ 0x02095CFC; symbol: func_02095cfc; size: 0x34.
extern "C" ARM void ApplyValueThroughThreeStateHandlers(void* p,int value){InvokeBoundedIndexWithModeThree(ReadGlobalValueAt02108844(),value);CountedKeyRecords_RemoveById(p,value);ApplyBoundedIdAndUpdateRecordState(p,value);}
