#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FA580; symbol: Unclassified_GetWordAtOffset1C_021FA580; size: 0x8.
// Returns the 32-bit word at object byte offset 0x1c; this address suffix temporarily distinguishes an otherwise identical accessor.
extern "C" void *Menu_GetMessageTableLoadState(void *object) {
    return *(void **)((unsigned char *)object + 0x1c);
}
