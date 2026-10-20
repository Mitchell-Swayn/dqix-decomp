#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0219735C; symbol: func_ov017_0219735c; size: 0x38.
extern "C" int Util_ContainsHalfwordValue(void* object, unsigned short value) {
    unsigned short* p = (unsigned short*)((char*)object + 0x44b8);
    int i = 0;
    while (i < 4) {
        if (*p == value)
            return 1;
        i++;
        p++;
    }
    return 0;
}
