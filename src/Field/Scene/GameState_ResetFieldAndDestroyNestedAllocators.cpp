#include <globaldefs.h>
ARM
extern "C" void FieldEvent_ReleaseResourcesAndResumeFieldControl(void);
extern "C" void Memory_DestroyNestedAndDetachedAllocators(void *);
// Original: arm9/ov017 @ 0x021BB8D8; symbol: GameState_ResetFieldAndDestroyNestedAllocators; size: 0x18.
// Calls the field-state cleanup routine and then Memory_DestroyNestedAndDetachedAllocators on the same object.
extern "C" void GameState_ResetFieldAndDestroyNestedAllocators(void *p) {
    FieldEvent_ReleaseResourcesAndResumeFieldControl();
    Memory_DestroyNestedAndDetachedAllocators(p);
}
