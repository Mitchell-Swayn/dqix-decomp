#include <globaldefs.h>
ARM
extern "C" void Reset128EntriesAndFlagArrays();extern "C" void ClearAndStageSharedGraphicsBuffers(void*);extern "C" void ResetEmbeddedOwnerAndAssignTwoBufferPointers(void*);
// Original: arm9/main @ 0x02043204; symbol: func_02043204; size: 0x20.
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void* p){Reset128EntriesAndFlagArrays();ClearAndStageSharedGraphicsBuffers(p);ResetEmbeddedOwnerAndAssignTwoBufferPointers(p);}
