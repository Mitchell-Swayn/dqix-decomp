#include <globaldefs.h>
ARM
extern "C" unsigned char data_02109bf4;
extern "C" void Object_SetUnsignedShortAtOffsetCEAndSetUnsignedCharAtOffsetC9To1(int, unsigned short);
// Original: arm9/ov004 @ 0x0215DE80; symbol: func_ov004_0215de80; size: 0x1C.
extern "C" int func_ov004_0215de80(void) {
    Object_SetUnsignedShortAtOffsetCEAndSetUnsignedCharAtOffsetC9To1((int)&data_02109bf4, 0x3d);
    return 0;
}
