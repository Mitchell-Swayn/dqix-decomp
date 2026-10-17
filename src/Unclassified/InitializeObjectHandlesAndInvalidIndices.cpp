#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" void ReplaceValueAndInvalidateFileIndices(int, int, int);
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(int, int);
extern "C" void Object_Invokewhile(void);
extern "C" void CleanupResourceGroupsToOwnerState(int);
extern "C" void Initialize1RecordFields_Main020BC078(int);
extern "C" void UpdateByteLevelTransitionAndThreeChannels(int, int, int);

// Original: arm9/main @ 0x0209C20C; symbol: func_0209c20c; size: 0x6C.
extern "C" void InitializeObjectHandlesAndInvalidIndices(int object) {
    ReplaceValueAndInvalidateFileIndices(object, 0, 0);
    DispatchObjectStateOneOrTwoUnlessFlag4(object, 0);
    Object_Invokewhile();
    CleanupResourceGroupsToOwnerState(object);
    *(int *)(object + 0xb0) = 0;
    *(int *)(object + 0xb4) = 0;
    *(short *)(object + 0xb8) = -1;
    Initialize1RecordFields_Main020BC078(object + 0xbc);
    *(short *)(object + 0xba) = -1;
    Initialize1RecordFields_Main020BC078(object + 0xc0);
    UpdateByteLevelTransitionAndThreeChannels(object, 0x7f, 0);
}
