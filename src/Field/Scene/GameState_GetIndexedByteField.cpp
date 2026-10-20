#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0219219C; symbol: func_ov017_0219219c; size: 0x60.
extern "C" char* GameState_GetIndexedByteField(char* object, int index) {
    int valid;
    if (index < 0) goto first_invalid;
    if (index <= 3) { valid = 1; goto first_done; }
first_invalid:
    valid = 0;
first_done:
    if (valid) return object + 0x2dc + 0x3400 + index;
    if (index < 0xc0) goto second_invalid;
    if (index <= 0xc7) { valid = 1; goto second_done; }
second_invalid:
    valid = 0;
second_done:
    if (valid) return object + 0xe1 + 0x3600 + (index - 0xc0);
    return 0;
}
