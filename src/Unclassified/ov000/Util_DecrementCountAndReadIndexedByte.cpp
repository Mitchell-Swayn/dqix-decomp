#include <globaldefs.h>
ARM
struct LargeObject { char padding[0x8000]; unsigned char fields[0xe48]; };
// Original: arm9/ov000 @ 0x0215FAD4; symbol: func_ov000_0215fad4; size: 0x30.
extern "C" int Util_DecrementCountAndReadIndexedByte(LargeObject *object) {
    unsigned int count = object->fields[0xe47];
    if (count == 0)
        return -1;
    int decremented = count - 1;
    unsigned int index = decremented & 0xff;
    object->fields[0xe47] = decremented;
    char *entry = (char *)object + index;
    entry += 0x8000;
    return *(unsigned char *)(entry + 0xe44);
}
