#include <globaldefs.h>
ARM
extern "C" void CutsceneCamera_InitializeCommandSession(void);
extern "C" void Object_ResetMotionStateAndChildRecords(void *);
// Original: arm9/ov001 @ 0x021588BC; symbol: Object_ResetMotionStateAndWriteHeaderWords; size: 0x28.
// Resets the object, writes the two supplied words at offsets 0 and 4, then resets its motion and child records.
extern "C" void CutsceneCamera_InitializeCommandPool(void *object, unsigned first, unsigned second) {
    CutsceneCamera_InitializeCommandSession();
    *(unsigned *)object = first;
    *(unsigned *)((char *)object + 4) = second;
    Object_ResetMotionStateAndChildRecords(object);
}
