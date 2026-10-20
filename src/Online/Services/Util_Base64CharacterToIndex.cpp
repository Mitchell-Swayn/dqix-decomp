#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0223E3D4; symbol: func_ov031_0223e3d4; size: 0x58.
extern "C" int Util_Base64CharacterToIndex(unsigned int character) {
    if (character >= 'A' && character <= 'Z') return character - 'A';
    if (character >= 'a' && character <= 'z') return character - 0x47;
    if (character >= '0' && character <= '9') return character + 4;
    if (character == '.') return 0x3E;
    if (character == '-') return 0x3F;
    return -1;
}
