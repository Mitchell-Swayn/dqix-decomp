#include <globaldefs.h>
ARM
extern "C" int CountNonzeroIndexedWords(void *object);
// Original: arm9/ov000 @ 0x02171968; symbol: func_ov000_02171968; size: 0x34.
extern "C" void func_ov000_02171968(unsigned char *object, int index, void *value) {
    if (index < 0 || index >= 0x93 || value == 0) return;
    *(void **)(object + 0x1A4 + index * 4) = value;
    *(unsigned short *)(object + 0x84) = (unsigned short)CountNonzeroIndexedWords(object);
}
