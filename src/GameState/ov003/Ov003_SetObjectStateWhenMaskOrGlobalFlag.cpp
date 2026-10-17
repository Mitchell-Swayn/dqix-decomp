#include <globaldefs.h>
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short *, unsigned int);
extern "C" unsigned short data_02114e30;
extern "C" unsigned char data_02114e54[];
// Original: arm9/ov003 @ 0x0217C74C; symbol: func_ov003_0217c74c; size: 0x54.
extern "C" void Ov003_SetObjectStateWhenMaskOrGlobalFlag(void *object) {
    if (Object_TestNewlySetHalfwordMask(&data_02114e30, 0x0c0f) == 0) {
        if (data_02114e54[0x5f] == 0 || *(unsigned short *)(data_02114e54 + 0x24) == 0) return;
    }
    *(unsigned char *)((char *)object + 0x140) = 4;
    *(unsigned char *)((char *)object + 0x141) = 0;
}
