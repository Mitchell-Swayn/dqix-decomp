#include <globaldefs.h>
ARM
extern "C" void BestiaryScreen_DrawMonsterDetails(unsigned char *p);
// Original: arm9/ov017 @ 0x021C0520; symbol: func_ov017_021c0520; size: 0x18.
extern "C" void FieldScreen_DrawOptionalMappedObjects(void *object) {
    unsigned char *p = *(unsigned char **)((char *)object + 0x20);
    if (p)
        BestiaryScreen_DrawMonsterDetails(p);
}
