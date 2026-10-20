#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0223BAAC; symbol: Object_GetPackedEntryCount; size: 0x8.
// Returns the packed-entry count byte at object offset 0xc, used by the range visibility updater.
extern "C" unsigned int WfcUtility_GetSpriteGroupCount(void *object) {
    return *((unsigned char *)object + 0xc);
}
