#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void ResetRenderPartsAndDestroyOwnedAllocator(char*);
extern "C" void Object_ResetOneHundredTwentyEightTextEntriesAndPointers(char*);
extern "C" void Reset128EntriesAndFlagArrays(char*);
extern "C" void ClearAndStageSharedGraphicsBuffers(char*);
extern "C" void ResetEmbeddedOwnerAndAssignTwoBufferPointers(char*);
// Original: arm9/main @ 0x02043000; symbol: func_02043000; size: 0x40.
extern "C" void Object_ResetEmbeddedTextStateAndWord38(char* p){
    ResetRenderPartsAndDestroyOwnedAllocator(p+0x19e0);
    Object_ResetOneHundredTwentyEightTextEntriesAndPointers(p);
    Reset128EntriesAndFlagArrays(p);
    ClearAndStageSharedGraphicsBuffers(p);
    ResetEmbeddedOwnerAndAssignTwoBufferPointers(p);
    *(unsigned*)(p+0x38)=0;
}
