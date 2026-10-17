#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x021631D0; symbol: func_ov001_021631d0; size: 0x30.
extern "C" int ConsumeResourceByteIntoNestedSecondWord(void *output) {
    char *resources = (char *)GameResources_GetInstance();
    unsigned char *field = *(unsigned char **)(resources + 0x3734) + 0x105;
    unsigned char value = *field;
    *field = 0;
    SetNestedSecondWordForTypeThree(output, value);
    return 1;
}
