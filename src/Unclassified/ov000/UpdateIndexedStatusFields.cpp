#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02182498; symbol: func_ov000_02182498; size: 0x40.
extern "C" void UpdateIndexedStatusFields(void* object, int enabled) {
    unsigned char* bytes = (unsigned char*)object;
    if (enabled != 0) {
        if (bytes[0x6e8] != 0 && *(short*)(bytes + 0x6ec) == 0) {
            *(short*)(bytes + 0x6ec) = *(short*)(bytes + 0x6ea) + 5;
        }
        return;
    }
    bytes[0x6e8] = 0;
    bytes[0x6e9] = 0;
}
