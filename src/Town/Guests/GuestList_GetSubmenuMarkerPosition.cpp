#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0217063C; symbol: func_ov003_0217063c; size: 0x4C.
extern "C" void GuestList_GetSubmenuMarkerPosition(unsigned char *object, unsigned short *first, unsigned short *second) {
    if ((signed char)object[1] == 5 && ((*(unsigned short *)(object + 0x20) & 0x10) != 0 || (*(unsigned short *)(object + 0x20) & 4) != 0)) {
        *first = 0x2C;
        signed char value = (signed char)object[8];
        *second = (unsigned short)(value * 17 + 0x3A);
    } else {
        *first = 0;
        *second = 0;
    }
}
