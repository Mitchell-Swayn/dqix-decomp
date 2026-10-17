#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt02108844(void);
extern "C" unsigned short ComputeSixteenBitMaskFromIndexedPredicates(char *p);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021E9B00; symbol: func_ov023_021e9b00; size: 0x48.
extern "C" int Unclassified_SetNestedWordToSixteenPlusMaskPopulation(void *output) {
    unsigned int mask = ComputeSixteenBitMaskFromIndexedPredicates((char *)ReadGlobalValueAt02108844());
    unsigned int bits = 0xFFFF | (mask << 16);
    int count = 0;
    while (bits != 0) {
        count += bits & 1;
        bits >>= 1;
    }
    SetNestedSecondWordForTypeThree(output, count);
    return 1;
}
