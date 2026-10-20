#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0220C090; symbol: Math_LoadSingleLimbDivisionEstimate; size: 0xC.
// Places a halfword in the upper word of a 64-bit result, with a zero lower word.
// The caller stores both return registers and uses this as a long-division estimate divisor.
extern "C" unsigned long long Math_LoadSingleLimbDivisionEstimate(const unsigned short* value) {
    return (unsigned long long)*value << 32;
}
