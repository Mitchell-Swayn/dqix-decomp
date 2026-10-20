#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x02195550; symbol: func_ov017_02195550; size: 0x3C.
extern "C" int Ov017_IsStateFlagSet(char *state) {
    if (*(unsigned char *)(state + 0x431e)) return 1;
    if (**(unsigned char **)(state + 0x441c)) return 1;
    return *(unsigned char *)(state + 0x42f0) != 0;
}
