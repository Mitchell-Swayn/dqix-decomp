#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F9C30; symbol: SetByteAtOffset62; size: 0x8.
// Stores the byte at object offset 0x62.
extern "C" void Menu_SetGridXButtonConfirms(void *object, unsigned char value) {
    *((unsigned char *)object + 0x62) = value;
}
