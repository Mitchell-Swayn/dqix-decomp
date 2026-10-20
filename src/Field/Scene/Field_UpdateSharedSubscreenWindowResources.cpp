#include <globaldefs.h>
ARM
extern "C" void Menu_UpdatePartyPreviewEquipmentWindow(void *object);
// Original: arm9/ov017 @ 0x021A18A4; symbol: func_ov017_021a18a4; size: 0x24.
extern "C" void Field_UpdateSharedSubscreenWindowResources(void *object) {
    if (*((unsigned char *)object + 0x22) <= 1)
        return;
    void *linked = *(void **)((char *)object + 0x1c);
    if (linked == 0)
        return;
    Menu_UpdatePartyPreviewEquipmentWindow(linked);
}
