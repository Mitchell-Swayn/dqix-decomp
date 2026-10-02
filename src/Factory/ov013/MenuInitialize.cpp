// Embed the implicit layer copies under the project-wide -inline noauto option.
#pragma always_inline on
#include "MenuText.h"

// Only the borrowed background buffer and widget group are observed here.
struct Ov013MenuParent {
    unsigned char unknown00[0x178];
    void* characterData;
    unsigned char unknown17C[12];
    Ov013WidgetGroup widgetGroup;
};

extern "C" {
void func_02074b64(void*);
void func_02074af4(void*);
void func_0205cfd4(Ov013WidgetGroup*);
void func_0205c790(void*);
void func_0204af64(void*);
void func_0204c684(Ov013Widget*);
void func_020dfc40(Ov013StringCatalog*);
}

extern "C" void func_ov013_02184360(Ov013Menu* menu, Ov013MenuParent* parent)
{
    menu->unknown30[0] = 0;
    menu->unknown30[1] = 0;
    if (parent)
        menu->borrowedGroup = 1;
    else
        menu->borrowedGroup = 0;
    if (menu->borrowedGroup) {
        func_02074b64(menu->graphicsState);
        menu->savedBackgroundMode = (*(volatile unsigned int*)0x04001000 & 0x1f00) >> 8;
    } else {
        func_02074af4(menu->graphicsState);
        volatile unsigned int* control = (volatile unsigned int*)0x04000000;
        menu->savedBackgroundMode = (*control & 0x1f00) >> 8;
        *control = (*control & ~0x1f00) | 0x100;
    }
    func_0205cfd4(&menu->widgetGroup);
    func_0205c790(menu->unknown3D4);
    if (menu->borrowedGroup) {
        Ov013WidgetGroup* group = &parent->widgetGroup;
        menu->widgetGroup.primary = group->primary;
        menu->widgetGroup.secondary = group->secondary;
        menu->widgetGroup.flags[0] = group->flags[0];
        menu->widgetGroup.flags[1] = group->flags[1];
        menu->widgetGroup.flags[2] = group->flags[2];
        menu->widgetGroup.flags[3] = group->flags[3];
        menu->widgetGroup.resources = group->resources;
        menu->widgetGroup.widgets = group->widgets;
        menu->widgetGroup.dimensions[0] = group->dimensions[0];
        menu->widgetGroup.dimensions[1] = group->dimensions[1];
        menu->widgetGroup.dimensions[2] = group->dimensions[2];
        menu->widgetGroup.dimensions[3] = group->dimensions[3];
        menu->widgetGroup.dimensions[4] = group->dimensions[4];
        menu->widgetGroup.dimensions[5] = group->dimensions[5];
        menu->widgetGroup.dimensions[6] = group->dimensions[6];
        menu->widgetGroup.dimensions[7] = group->dimensions[7];
        menu->widgetGroup.state[0] = group->state[0];
        menu->widgetGroup.state[1] = group->state[1];
        menu->widgetGroup.state[2] = group->state[2];
        menu->widgetGroup.state[3] = group->state[3];
        menu->widgetGroup.state[4] = group->state[4];
        menu->widgetGroup.state[5] = group->state[5];
        menu->widgetGroup.state[6] = group->state[6];
        menu->widgetGroup.state[7] = group->state[7];
        menu->widgetGroup.state[8] = group->state[8];
        menu->widgetGroup.state[9] = group->state[9];
        menu->widgetGroup.state[10] = group->state[10];
        menu->widgetGroup.state[11] = group->state[11];
    }
    for (int i = 0; i < 2; ++i)
        func_0204af64(menu->resourceSlots[i]);
    for (int i = 0; i < 3; ++i)
        func_0204c684(&menu->widgets[i]);
    menu->stringAllocator.ResetAllocatorPointer();
    func_020dfc40(&menu->strings);
    menu->allocator.ResetAllocatorPointer();
    for (int i = 0; i < 3; ++i)
        menu->state[i] = 0;
    menu->translationStep = 0;
    menu->display = 0;
    menu->displayId = 0xff;
    menu->displayOffset = 0;
    menu->state[4] = 0;
    menu->state[5] = 0;
    menu->state[6] = 0;
    menu->state[7] = 0;
    menu->tickCount = 0;
    menu->mode = 0;
    menu->unknown64C = 0;
    menu->primarySelection = 0;
    menu->optionSelection = 0;
    menu->flags664[0] = 0;
    menu->flags664[1] = 0;
    menu->unknown668 = 0;
    menu->unknown66C = 0;
    menu->unknown670 = 0;
    menu->unknown6B0 = 0;
    menu->flag6B4 = 0;
    menu->textBuffer = 0;
    menu->unknown6A4 = 0;
    menu->flag6A8 = 0;
    menu->cursorFlags = 0;
    menu->unknown6B8 = 0;
    menu->cursorValues[0] = 0;
    menu->cursorValues[1] = 0;
    menu->cursorValues[2] = 0;
    menu->cursorValues[3] = 0;
    menu->cursorValues[4] = 0;
    menu->cursorValues[5] = 0;
    menu->cursorValues[6] = 0;
    for (int i = 0; i < 5; ++i)
        menu->primaryValues[i] = 0;
    for (int i = 0; i < 5; ++i)
        menu->secondaryValues[i] = 0;
    for (int i = 0; i < 5; ++i)
        menu->enabled[i] = 1;
    menu->unknown654 = menu->borrowedGroup ? parent->characterData : 0;
    for (int i = 0; i < 5; ++i)
        menu->flags6A9[i] = 0;
}
