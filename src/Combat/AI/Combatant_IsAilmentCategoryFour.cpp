#include <globaldefs.h>
ARM
// Original: arm9/ov024:021edc80; Reads byte +0x21 through the object pointer at +0x138 and returns whether it equals 4.
extern "C" int Combatant_IsAilmentCategoryFour(void *obj) {
    unsigned int value = *(unsigned char *)(*(unsigned int *)((char *)obj + 0x138) + 0x21);
    int match = value == 4;
    return match != 0;
}
