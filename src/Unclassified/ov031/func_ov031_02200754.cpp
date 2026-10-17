#include <globaldefs.h>
ARM
extern "C" int func_ov031_022006f0(unsigned int);
extern "C" unsigned char data_ov031_0224c980[];

// Original: arm9/ov031 @ 0x02200754; symbol: func_ov031_02200754; size: 0x3C.
extern "C" int func_ov031_02200754(unsigned int value) {
    int result = 0;
    if (func_ov031_022006f0(value)) {
        unsigned int required = ~*(unsigned int *)(data_ov031_0224c980 + 0x1c);
        if ((required & value) == required)
            result = 1;
    }
    return result;
}
