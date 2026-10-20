#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance(void);
// Original: arm9/ov001 @ 0x0215E588; symbol: SetBit7OnObjectAtOffset195B; size: 0x28.
// Reads the object pointer from field +0x1C and sets bit 7 at byte offset 0x195B when the pointer is nonnull.
extern "C" unsigned Script_EnableOutlinedMessageGlyphs(void) {
    char *object = (char *)TextContext_GetSharedInstance();
    if (!object)
        return 0;
    *((unsigned char *)object + 0x195b) |= 0x80;
    return 1;
}
