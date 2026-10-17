#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void *);
extern "C" int ReadScriptParameterAsInteger(void *parameter);
// Original: arm9/ov001 @ 0x0215E97C; symbol: func_ov001_0215e97c; size: 0x34.
extern "C" int SetObjectField19CBFromScriptParameter(void *parameter) {
    unsigned int object = ReadWordFieldAtOffset1C(parameter);
    int enabled = ReadScriptParameterAsInteger(parameter) != 0;
    *((unsigned char *)object + 0x19cb) = (unsigned char)enabled;
    return 1;
}
