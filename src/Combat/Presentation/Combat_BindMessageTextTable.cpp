#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021ED31C; symbol: Combat_SetWordAtOffset168; size: 0x8.
// Stores the supplied 32-bit value at object byte offset 0x168; the combat caller supplies the object and field value.
extern "C" void Combat_BindMessageTextTable(void *object, unsigned int value) {
    *(unsigned int *)((unsigned char *)object + 0x168) = value;
}
