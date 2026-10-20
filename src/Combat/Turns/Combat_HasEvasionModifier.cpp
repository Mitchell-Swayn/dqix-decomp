#include <globaldefs.h>
// Original: arm9/ov000 @ 0x021563ec; symbol: func_ov000_021563ec; size: 0x18.
extern "C" int Combat_HasEvasionModifier(const void* object) {
    const unsigned char* bytes = static_cast<const unsigned char*>(object);
    const unsigned char* nested = *reinterpret_cast<const unsigned char* const*>(bytes + 0x138);
    const unsigned int flags = *reinterpret_cast<const unsigned int*>(nested + 0x14);
    return (flags & 0x02000000) != 0;
}
