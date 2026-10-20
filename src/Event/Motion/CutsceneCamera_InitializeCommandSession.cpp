#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
extern "C" void Object_ResetMotionStateAndChildRecords(void *);
// Original: arm9/ov001 @ 0x02158880; symbol: InitializeObjectAndClearTwoSubstructures; size: 0x3C.
// Clears object words +0/+4 and two 12-byte blocks at +0x4C/+0x58, then calls the object initializer.
extern "C" void CutsceneCamera_InitializeCommandSession(void *obj) {
    *(unsigned int *)obj = 0;
    *(unsigned int *)((char *)obj + 4) = 0;
    memset((char *)obj + 0x4c, 0, 0xc);
    memset((char *)obj + 0x58, 0, 0xc);
    Object_ResetMotionStateAndChildRecords(obj);
}
