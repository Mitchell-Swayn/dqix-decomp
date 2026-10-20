#include <globaldefs.h>
ARM
extern "C" void EquipmentMenu_UpdateReadyDisplayResources(void *);
// Original: arm9/ov023 @ 0x021E3184; symbol: func_ov023_021e3184; size: 0x2C.
extern "C" void Menu_UpdatePartyPreviewEquipmentWindow(void *object) {
    signed char value = *(signed char *)((unsigned char *)object + 0x4E6);
    if (value != 0) {
        if (value != -1) {
            void *pointer = *(void **)object;
            if (pointer != 0)
                EquipmentMenu_UpdateReadyDisplayResources(pointer);
        }
    }
}
