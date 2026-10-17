#include <globaldefs.h>
extern "C" char data_02114e30[],data_02114e54[];
extern "C" void PowerManagement_HandleLidStateAndResourceTransitions();
extern "C" void ClearModeTimestampAndEnableTwoInputOwners();
extern "C" void UpdateCurrentAndPreviousInputState(void*);
extern "C" void TouchInput_UpdateSampleAndPressState(void*);
// Original: arm9/main @ 0x02012EFC; symbol: func_02012efc; size: 0x28.
extern "C" void UpdateInputStatesAndCallbacks() {PowerManagement_HandleLidStateAndResourceTransitions();ClearModeTimestampAndEnableTwoInputOwners();UpdateCurrentAndPreviousInputState(data_02114e30);TouchInput_UpdateSampleAndPressState(data_02114e54);}
