#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215570C; symbol: func_ov003_0215570c; size: 0x34.
extern "C" int CountNonNullEntries12(char* object) {
    int count = 0;
    unsigned char index = 0;
    for (; index < 12; ++index) {
        if ((*(void***)(object + 0x20))[index] != 0) ++count;
    }
    return count;
}
