#include "MenuText.h"

extern "C" {
void* memset(void*, int, unsigned int);
void func_0205de24(Ov013WidgetGroup*, int, int);
void func_0205d304(Ov013WidgetGroup*, Ov013TextBuffer*, int, int, int, int, int, int);
void func_0205ba68(void*, int, int, int);
void func_0205bacc(void*, int);
void func_0205bcdc(void*, int);
void func_0205bb04(void*, int);
}

#pragma force_active on
extern "C" void func_ov013_02185310(Ov013Menu* menu)
{
    func_0205de24(&menu->widgetGroup, 0, 2);
    menu->widgetGroup.dimensions[0] = 30;
    menu->widgetGroup.dimensions[1] = 13;
    menu->widgetGroup.dimensions[2] = 1;
    menu->widgetGroup.dimensions[3] = 0;
    menu->widgetGroup.dimensions[4] = 0;
    menu->widgetGroup.dimensions[5] = 5;
    menu->widgetGroup.dimensions[6] = 10;
    menu->widgetGroup.dimensions[7] = 13;
    menu->widgetGroup.state[1] = 0;
    if (menu->borrowedGroup)
        menu->widgetGroup.state[5] = 0;
    else
        menu->widgetGroup.state[5] = 1;
    memset(menu->textBuffer, 0, 0x960);
    func_ov013_02185424(menu, menu->textBuffer);
    func_0205d304(&menu->widgetGroup, menu->textBuffer, 0, 0, 0, 1, 0, 0);
    menu->widgetGroup.state[1] = 0;
    menu->widgetGroup.primary.words[1] = 1;
    menu->widgetGroup.secondary.words[1] = 1;
    func_0205ba68(&menu->widgetGroup.primary, 1, 6, 0);
    func_0205ba68(&menu->widgetGroup.secondary, 1, 6, 0);
    func_0205bacc(&menu->widgetGroup.primary, 6);
    func_0205bacc(&menu->widgetGroup.secondary, 6);
    func_0205bcdc(&menu->widgetGroup.primary, 1);
    func_0205bb04(&menu->widgetGroup.secondary, 1);
}
