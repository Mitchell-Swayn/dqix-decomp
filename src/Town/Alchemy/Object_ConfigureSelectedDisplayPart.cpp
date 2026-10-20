#include <globaldefs.h>
ARM
extern "C" void TextCanvas_SetEntryMessageKey(char *, int, short);
extern "C" void TextCanvas_SetEntryTextAlignmentMode(char *, int, int);
extern "C" void TextCanvas_SetGroupInteriorFillSuppressed(unsigned char *, int, int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char *, int);
extern "C" void TextCanvas_SetGroupPalette(char *, int, unsigned char);
extern "C" void TextCanvas_ShowDisplayPart(unsigned char *, int);

// Original: arm9/ov006 @ 0x0215FCF0; symbol: func_ov006_0215fcf0; size: 0x70.
extern "C" void Object_ConfigureSelectedDisplayPart(void *object) {
    unsigned char value = *((unsigned char *)object + 0x386);
    char *part = *(char **)((unsigned char *)object + 0x14);
    TextCanvas_SetEntryMessageKey(part, 0x5a, (short)(value + 0x29));
    TextCanvas_SetEntryTextAlignmentMode(part, 0x5a, 1);
    TextCanvas_SetGroupInteriorFillSuppressed((unsigned char *)part, 0xf, 1);
    TextCanvas_CreateAndConfigureDisplayPart(part, 0xf);
    TextCanvas_SetGroupPalette(part, 0xf, 2);
    TextCanvas_ShowDisplayPart((unsigned char *)part, 0xf);
}
