#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022115D0; symbol: Unclassified_GetWordAtOffset1C_022115D0; size: 0x8.
// Returns the 32-bit word at object byte offset 0x1c; this address suffix temporarily distinguishes an otherwise identical accessor.
extern "C" void *SwcaRecord_GetAssociatedIdentifier(void *object) {
    return *(void **)((unsigned char *)object + 0x1c);
}
