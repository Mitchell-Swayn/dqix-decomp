#include <globaldefs.h>
ARM
extern "C" void TextCanvas_ShowDisplayPart(unsigned char*, int);
extern "C" void TextCanvas_SetGroupPalette(char*, int, unsigned char);
extern "C" void TextCanvas_SetEntryNumericValue(char*, int, int);
extern "C" void TextCanvas_HideEntry(unsigned char*, int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*, int);
// Original: arm9/ov003 @ 0x02177208; symbol: func_ov003_02177208; size: 0x64.
extern "C" void Object_InitializeSelectedPartNine(void* object) {
    char* part = *(char**)((char*)object + 0x89c);
    TextCanvas_ShowDisplayPart((unsigned char*)part, 9);
    TextCanvas_SetGroupPalette(part, 9, 0);
    int value = *(unsigned char*)((char*)object + 0x103c);
    TextCanvas_SetEntryNumericValue(part, 0x57, value);
    TextCanvas_HideEntry((unsigned char*)part, 0x58);
    TextCanvas_HideEntry((unsigned char*)part, 0x59);
    TextCanvas_CreateAndConfigureDisplayPart(part, 9);
}
