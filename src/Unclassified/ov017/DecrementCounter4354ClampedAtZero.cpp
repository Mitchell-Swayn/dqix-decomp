#include <globaldefs.h>
ARM

// Decrements the signed byte counter at offset 0x4354, clamping it at zero.
// Original: arm9/ov017 @ 0x021A4E48; symbol: func_ov017_021a4e48; size: 0x28.
extern "C" void DecrementCounter4354ClampedAtZero(char *object)
{
    *(signed char *)(object + 0x4354) -= 1;
    if (*(signed char *)(object + 0x4354) < 0) {
        *(signed char *)(object + 0x4354) = 0;
    }
}
