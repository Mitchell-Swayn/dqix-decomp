#include <globaldefs.h>
// Original: arm9/ov000 @ 0x02159904; symbol: func_ov000_02159904; size: 0x18.
extern "C" int HasNestedObjectFlag04(const void* object) {
    const unsigned char* bytes = static_cast<const unsigned char*>(object);
    const unsigned char* nested = *reinterpret_cast<const unsigned char* const*>(bytes + 0x138);
    const unsigned int flags = *reinterpret_cast<const unsigned int*>(nested + 0x18);
    return (flags & 4) != 0;
}
