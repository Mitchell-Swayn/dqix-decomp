#include <globaldefs.h>
ARM
extern "C" unsigned char data_02109bf4[];
extern "C" unsigned char data_02108760[];
extern "C" unsigned char ReadByteFieldAtOffsetCC(int object);
extern "C" unsigned char Object_ReadByteAtOffsetCC(int object);
// Original: arm9/ov002 @ 0x0215B234; symbol: func_ov002_0215b234; size: 0x34.
extern "C" void func_ov002_0215b234(unsigned char *object) {
    *(unsigned char *)(object + 0x1C2C) = ReadByteFieldAtOffsetCC((int)data_02109bf4);
    *(unsigned char *)(object + 0x1C2D) = Object_ReadByteAtOffsetCC((int)data_02108760);
}
