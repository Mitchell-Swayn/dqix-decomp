#include <globaldefs.h>
ARM
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov001 @ 0x02157C1C; symbol: func_ov001_02157c1c; size: 0x20.
extern "C" int CutsceneCamera_ApplyTargetPositionCommand(void *sourceObject, void *destinationObject) {
    memcpy((char *)destinationObject + 0x58, (char *)sourceObject + 0x10, 12);
    return 0;
}
