#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02156404; symbol: func_ov000_02156404; size: 0x18.
extern "C" int Combat_HasFixedReactionChanceStatus(void *object) {
    unsigned int *pointer = *(unsigned int **)((unsigned char *)object + 0x138);
    return (pointer[6] & 0x400) != 0;
}
