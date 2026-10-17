#include <globaldefs.h>
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/main @ 0x02069974; symbol: func_02069974; size: 0x28.
extern "C" unsigned int WriteEncodedTextMarkerFF28(unsigned int *param_1, unsigned int unused2, unsigned int unused3, unsigned int unused4) {
    void *destination = (void *)*param_1;
    unsigned short local = 0xff28;
    memcpy(destination, &local, 2);
    return 2;
}
