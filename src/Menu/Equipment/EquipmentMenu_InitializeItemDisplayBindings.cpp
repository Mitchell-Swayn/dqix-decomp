#include <globaldefs.h>
ARM

// Offsets and strides follow the initializer and its item-display consumers.
// Unobserved portions retain byte storage until their interfaces are recovered.
struct EquipmentItemModel { unsigned char unknown[0x70]; };
struct EquipmentItemDisplay {
    unsigned char unknown[0x1c];
    int x, y, z;
    unsigned char tail[0x60];
};
struct EquipmentItemBinding {
    unsigned unknown;
    EquipmentItemModel *model;
    EquipmentItemDisplay *display;
    int x, y;
    unsigned char tail[8];
};
struct EquipmentDisplayState {
    unsigned char prefix[0x304];
    EquipmentItemModel models[24];
    unsigned char middle[0x200c];
    EquipmentItemBinding bindings[24];
    EquipmentItemDisplay displays[24];
};

#pragma force_active on
// Original: arm9/ov005 @ 0x02155424; symbol: func_ov005_02155424; size: 0x120.
// Connects equipment and inventory slots to model and positioned display records.
extern "C" void EquipmentMenu_InitializeItemDisplayBindings(EquipmentDisplayState *state)
{
    for (int i = 0; i < 8; ++i) {
        EquipmentItemBinding *binding = &state->bindings[i];
        binding->model = &state->models[i];
        binding->display = &state->displays[i];
        binding->x = 133 << 12;
        binding->y = 22 << 12;
        EquipmentItemDisplay *display = binding->display;
        display->x = 133 << 12;
        display->y = 22 << 12;
        display->z = 0;
    }
    for (int i = 0; i < 16; ++i) {
        int cell = i % 16;
        int column = cell % 4;
        int row = cell / 4;
        EquipmentItemBinding *binding = &state->bindings[i + 8];
        binding->model = &state->models[i + 8];
        binding->display = &state->displays[i + 8];
        int x = (column * 26 + 141) << 12;
        int y = (row * 26 + 52) << 12;
        binding->x = x;
        binding->y = y;
        EquipmentItemDisplay *display = binding->display;
        display->x = x;
        display->y = y;
        display->z = 0;
    }
}
