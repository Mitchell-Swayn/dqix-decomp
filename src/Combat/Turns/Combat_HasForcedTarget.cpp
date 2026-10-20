#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02155154; symbol: func_ov000_02155154; size: 0x18.
extern "C" int Combat_HasForcedTarget(void* object) {
    unsigned char* bytes = (unsigned char*)object;
    unsigned int state = *(unsigned int*)(*(unsigned int*)(bytes + 0x138) + 0x18);
    return (state & 0x1000) != 0;
}
