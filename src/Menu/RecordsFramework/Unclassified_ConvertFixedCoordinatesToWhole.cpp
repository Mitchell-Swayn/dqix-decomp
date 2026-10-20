#include <globaldefs.h>
ARM

// Original: arm9/ov023 @ 0x021F8AEC; symbol: func_ov023_021f8aec; size: 0x44.
extern "C" void Unclassified_ConvertFixedCoordinatesToWhole(void *out, const int *values) {
    *(unsigned short *)((char *)out + 0x3a) = (unsigned short)((float)values[0] / 4096.0f);
    *(unsigned short *)((char *)out + 0x3c) = (unsigned short)((float)values[1] / 4096.0f);
}
