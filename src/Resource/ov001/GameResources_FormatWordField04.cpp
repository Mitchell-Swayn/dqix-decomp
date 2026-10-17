#include <globaldefs.h>
ARM

extern "C" void *GameResources_GetInstance();
extern "C" int OV017_ReadWordField04(void *);
extern "C" int sprintf(char *buffer, const char *format, ...);
extern "C" const char data_ov001_02165745[];

// Original: arm9/ov001 @ 0x021613D0; symbol: func_ov001_021613d0; size: 0x38.
extern "C" int GameResources_FormatWordField04(void *object) {
    char *base = *(char **)((char *)GameResources_GetInstance() + 0x3734);
    char *buffer = base + 0xd8;
    unsigned int value = OV017_ReadWordField04(object);
    sprintf(buffer, data_ov001_02165745, value);
    return 1;
}
