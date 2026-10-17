#include <globaldefs.h>
ARM

extern "C" unsigned ReadOptionalObjectByteNine(void);
extern "C" unsigned SelectStateWordByPriorityMask(unsigned);
extern "C" unsigned func_ov031_02213ce0(void);
extern "C" unsigned func_ov031_02213dd8(void);

// Original: arm9/ov031 @ 0x02213C9C; symbol: func_ov031_02213c9c; size: 0x44.
extern "C" unsigned System_SelectStateHandlerByOptionalByte(void) {
    unsigned value = ReadOptionalObjectByteNine();
    SelectStateWordByPriorityMask(0x10);
    switch (value) {
    case 7:
        value = func_ov031_02213ce0();
        break;
    case 8:
        value = func_ov031_02213dd8();
        break;
    default:
        break;
    }
    return value;
}
