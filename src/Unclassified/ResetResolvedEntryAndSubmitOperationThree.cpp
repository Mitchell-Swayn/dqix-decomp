#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int RecordArray_FindFourEntryTagAndOptionalKeyMatch(void);
extern "C" void InitializeInvalidWordAndThreeClearBytes(void);
extern "C" void Object_GetGlobalConnectionState(void);
extern "C" int TestInactiveOrPrimaryIndexState(void);
extern "C" void QueueTaggedRecordOperationMessage34(unsigned int, unsigned int, unsigned int);
// Original: arm9/main @ 0x020E3994; symbol: func_020e3994; size: 0x40.
extern "C" void ResetResolvedEntryAndSubmitOperationThree(unsigned int unused, unsigned int param_2, unsigned int param_3) {
    if (RecordArray_FindFourEntryTagAndOptionalKeyMatch() == 0) return;
    InitializeInvalidWordAndThreeClearBytes();
    Object_GetGlobalConnectionState();
    if (TestInactiveOrPrimaryIndexState() == 0) return;
    QueueTaggedRecordOperationMessage34(3, param_2 & 0xff, param_3);
}
