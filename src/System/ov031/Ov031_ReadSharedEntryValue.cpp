#include <globaldefs.h>
ARM
extern "C" unsigned int GetOverlaySharedWord();
// Original: arm9/ov031 @ 0x0220EDB4; symbol: func_ov031_0220edb4; size: 0x30.
extern "C" unsigned int Ov031_ReadSharedEntryValue(void) {
    unsigned char *base = (unsigned char *)(GetOverlaySharedWord() + 0x2000);
    unsigned *entry = *(unsigned **)(base + 0x270);
    if (entry) {
        unsigned index = *(unsigned *)(base + 0x274);
        if (index > 0xC) return *(unsigned *)(entry + 1);
    }
    return 0;
}
