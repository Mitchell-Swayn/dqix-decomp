#include "ItemSelection.h"

#pragma dont_inline on

extern "C" void func_ov006_02158fd8(ItemSelection* self, unsigned char category,
                                     short id, unsigned char quantity);

extern "C" void func_ov006_02159094(ItemSelection* self)
{
    for (signed char i = 2; i >= 0; --i) {
        if (self->pendingIds[i] > 0) {
            func_ov006_02158fd8(self, (unsigned char)self->pendingCategories[i],
                              self->pendingIds[i], self->pendingQuantities[i]);
            self->pendingCategories[i] = 0;
            self->pendingIds[i] = -1;
            self->pendingQuantities[i] = 0;
            return;
        }
    }
}

extern "C" void func_ov006_02159108(ItemSelection* self, unsigned char category,
                                     short id, unsigned char quantity)
{
    short* ids = self->categoryIds[category];
    unsigned char* quantities = self->categoryQuantities[category];
    unsigned short count = self->categoryCounts[category];
    for (unsigned short i = 0; i < count; ++i) {
        if (id == ids[i])
            quantities[i] -= quantity;
    }
    for (unsigned char i = 0; i < 3; ++i) {
        if (self->pendingIds[i] <= 0) {
            self->pendingCategories[i] = category;
            self->pendingIds[i] = id;
            self->pendingQuantities[i] = quantity;
            return;
        }
    }
}
