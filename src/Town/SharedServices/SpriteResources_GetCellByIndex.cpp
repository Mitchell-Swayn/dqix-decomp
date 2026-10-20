#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x02173BB0; symbol: func_ov003_02173bb0; size: 0x28.
extern "C" void *SpriteResources_GetCellByIndex(void *object, unsigned int index) {
    unsigned char *records = *(unsigned char **)((unsigned char *)object + 0x40);
    void *result = 0;
    if (records != 0 && index < *(unsigned short *)((unsigned char *)object + 0x4e))
        result = records + index * 0x28;
    return result;
}
