#include <globaldefs.h>

// InitializeTwoWordsAndTwoHalfwords; field semantics beyond the observed offsets and masks remain unknown.
// Original: arm9/ov023 @ 0x021E1318; symbol: func_ov023_021e1318; size: 0x18.
extern "C" void Menu_ResetCatalogue(void *object)
{
    unsigned int *words = (unsigned int *)object;
    unsigned short *halfwords = (unsigned short *)((unsigned char *)object + 8);
    words[0] = 0;
    words[1] = 0;
    halfwords[0] = 0;
    halfwords[1] = 0;
}
