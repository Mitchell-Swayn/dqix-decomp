#include "ItemSelection.h"

extern "C" {
void func_ov006_0215f3d8(ItemSelection* self);
void func_ov006_0215f740(ItemSelection* self);
int func_ov006_021595b4(ItemSelection* self);
}

extern "C" int func_ov006_02159564(ItemSelection* self)
{
    self->activeControl = &self->entryControl;
    func_ov006_0215f3d8(self);
    if (self->previousControl != *self->activeControl) {
        func_ov006_0215f740(self);
        return 0;
    }
    return func_ov006_021595b4(self) != 0;
}
