#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void *);
extern "C" int Script_ReadParameterAsInteger(void *parameter);
// Original: arm9/ov001 @ 0x0215E97C; symbol: func_ov001_0215e97c; size: 0x34.
extern "C" int Script_SetPersistentMessageFrame(void *parameter) {
    unsigned int object = TextContext_GetSharedInstance(parameter);
    int enabled = Script_ReadParameterAsInteger(parameter) != 0;
    *((unsigned char *)object + 0x19cb) = (unsigned char)enabled;
    return 1;
}
