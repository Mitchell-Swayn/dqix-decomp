#include "ItemSelection.h"

extern "C" void func_ov006_0215951c(ItemSelection* self)
{
    self->page = 0;
    short category = self->categoryControl - 0x5b;
    self->pageCount = (self->categoryCounts[category] + 7) / 8;
    if (!self->pageCount)
        self->pageCount = 1;
}
