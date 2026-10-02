#include "ItemSelection.h"

#pragma dont_inline on

extern "C" short* func_ov006_0215919c(ItemSelection* self)
{
    short category = self->categoryControl - 0x5b;
    short* ids = 0;
    if (category >= 0)
        ids = self->categoryIds[category];
    return ids;
}

extern "C" unsigned char* func_ov006_021591c4(ItemSelection* self)
{
    short category = self->categoryControl - 0x5b;
    unsigned char* quantities = 0;
    if (category >= 0)
        quantities = self->categoryQuantities[category];
    return quantities;
}

extern "C" unsigned short func_ov006_021591ec(ItemSelection* self)
{
    short category = self->categoryControl - 0x5b;
    unsigned short count = 0;
    if (category >= 0)
        count = self->categoryCounts[category];
    return count;
}

extern "C" int func_ov006_02159218(ItemSelection* self)
{
    short* ids = func_ov006_0215919c(self);
    unsigned short count = func_ov006_021591ec(self);
    int available = 0;
    if (ids) {
        for (unsigned short i = 0; i < count; ++i) {
            if (ids[i] > 0) {
                available = 1;
                break;
            }
        }
    }
    return available;
}

extern "C" void func_ov006_02159274(ItemSelection* self,
                                    unsigned char* categoryOut, short* idOut,
                                    unsigned char* quantityOut)
{
    *categoryOut = 0;
    *idOut = -1;
    *quantityOut = 0;
    if (self->entryControl < 0)
        return;
    short category = self->categoryControl - 0x5b;
    short* ids = func_ov006_0215919c(self);
    unsigned char* quantities = func_ov006_021591c4(self);
    unsigned short count = func_ov006_021591ec(self);
    if (!ids || !quantities || !count)
        return;
    unsigned short index = self->page * 8;
    index += self->entryControl - 0x64;
    *categoryOut = category;
    *idOut = ids[index];
    *quantityOut = quantities[index];
}
