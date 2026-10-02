#include "ItemSelection.h"

#pragma dont_inline on

extern "C" {
void func_ov006_0215f4dc(ItemSelection* self);
void func_02080fa8(ItemSelectionMenu* menu, int control, int value);
int func_020813ec(ItemSelectionMenu* menu, int event);
}

// The extractor fills all four bytes, including the two values unused here.
struct SelectedItem {
    unsigned char quantity;
    unsigned char category;
    short id;
};

extern "C" void func_ov006_02159320(ItemSelection* self)
{
    SelectedItem selected;
    func_ov006_02159274(self, &selected.category, &selected.id, &selected.quantity);
    if (selected.quantity > 9)
        selected.quantity = 9;
    if (selected.quantity) {
        unsigned char previous = self->requestedQuantity;
        ++self->requestedQuantity;
        if (selected.quantity < self->requestedQuantity)
            self->requestedQuantity = selected.quantity;
        if (previous != self->requestedQuantity)
            self->quantityIncreased = 1;
    }
    func_ov006_0215f4dc(self);
    func_02080fa8(self->menu, 0x1f, self->requestedQuantity);
    func_020813ec(self->menu, 6);
}

extern "C" void func_ov006_021593b0(ItemSelection* self)
{
    SelectedItem selected;
    func_ov006_02159274(self, &selected.category, &selected.id, &selected.quantity);
    if (selected.quantity > 9)
        selected.quantity = 9;
    if (selected.quantity) {
        unsigned char previous = self->requestedQuantity;
        --self->requestedQuantity;
        if (!self->requestedQuantity)
            self->requestedQuantity = 1;
        if (previous != self->requestedQuantity)
            self->quantityDecreased = 1;
    }
    func_ov006_0215f4dc(self);
    func_02080fa8(self->menu, 0x1f, self->requestedQuantity);
    func_020813ec(self->menu, 6);
}
