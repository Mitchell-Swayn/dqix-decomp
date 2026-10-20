#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02158038; symbol: func_ov001_02158038; size: 0x48.
// Copies source words 1–3 into the selected destination triplet at 0x64 or 0x88, sets the word at 0xA24 to one, and returns zero.
extern "C" int CutsceneCamera_ApplySelectedOrbitParameters(const unsigned int* source, unsigned char* destination) {
    if (*(unsigned int*)(destination + 0x70) != 0) {
        *(unsigned int*)(destination + 0x88) = source[1];
        *(unsigned int*)(destination + 0x8c) = source[2];
        *(unsigned int*)(destination + 0x90) = source[3];
    } else {
        *(unsigned int*)(destination + 0x64) = source[1];
        *(unsigned int*)(destination + 0x68) = source[2];
        *(unsigned int*)(destination + 0x6c) = source[3];
    }
    *(unsigned int*)(destination + 0xa24) = 1;
    return 0;
}
