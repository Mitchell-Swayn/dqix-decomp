#include <globaldefs.h>
extern "C" void *memcpy(void *, const void *, unsigned int);

// Original: arm9/main @ 0x02069B84; symbol: func_02069b84; size: 0x28.
extern "C" unsigned int TextStream_WriteMarkerFF08(unsigned int *destination, unsigned int unused2, unsigned int unused3, unsigned int unused4) {
    void *output = (void *)*destination;
    unsigned short local = 0xff08;
    memcpy(output, &local, 2);
    return 2;
}
