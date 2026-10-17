#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int ReplaceSelectedHalfwordBitsInRecordCollection(void *, void *, int, int, int, unsigned int);
// Original: arm9/main @ 0x0205AF38; symbol: func_0205af38; size: 0x4C.
extern "C" void Object_ApplyRecordConfigurationAndStoreTwoBytes(void *p1, void *p2, unsigned int p3, int p4) {
    if (p2 && ReplaceSelectedHalfwordBitsInRecordCollection(p1, p2, 0, 0x300, 8, p3 | ((unsigned int)(p4 << 0x11) >> 0x10)) == 0) {
        ((unsigned char *)p2)[0x23] = (unsigned char)p3;
        ((unsigned char *)p2)[0x24] = (unsigned char)p4;
    }
}
