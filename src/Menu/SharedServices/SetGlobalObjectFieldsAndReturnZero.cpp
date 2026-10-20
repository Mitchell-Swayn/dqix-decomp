#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov004 @ 0x02165AF4; symbol: func_ov004_02165af4; size: 0x20.
extern "C" int SetGlobalObjectFieldsAndReturnZero(void) {
    unsigned char *object = (unsigned char *)TextContext_GetSharedInstance();
    object[0x19b2] = 1;
    *(unsigned int *)(object + 0x99c) = 1;
    return 0;
}
