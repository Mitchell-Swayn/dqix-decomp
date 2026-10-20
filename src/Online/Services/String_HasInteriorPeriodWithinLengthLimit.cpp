#include <globaldefs.h>
ARM

extern "C" unsigned String_CountBytesUntilTerminator(const signed char *str);

// Original: arm9/ov031 @ 0x02210F24; symbol: func_ov031_02210f24; size: 0x54.
extern "C" int String_HasInteriorPeriodWithinLengthLimit(const signed char *str) {
    if (str != 0) {
        int length = String_CountBytesUntilTerminator(str);
        if (length > 2 && length <= 0x40) {
            int end = length - 1;
            int i = 1;
            if (end > 1) {
                do {
                    if (str[i] == 0x2e) return 1;
                    i++;
                } while (i < end);
            }
        }
    }
    return 0;
}
