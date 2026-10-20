#include <globaldefs.h>
ARM
// Original: arm9/ov004 @ 0x021545F0; symbol: WriteIndexedSixByteRecord; size: 0x28.
// Writes two halfwords and two bytes into a six-byte record at base + 6*index.
extern "C" void Menu_StoreCategoryCompletionCounts(void *base, unsigned index, unsigned short first, unsigned short second, unsigned char byte0, unsigned char byte1) {
    char *entry = (char *)base + index * 6;
    *(unsigned short *)entry = first;
    *(unsigned short *)(entry + 2) = second;
    *((unsigned char *)entry + 4) = byte0;
    *((unsigned char *)entry + 5) = byte1;
}
