#include "MenuText.h"
#include <std_library_functions.h>

extern "C" void func_ov013_02186bd4(Ov013Menu* menu)
{
    memset(menu->textBuffer, 0, sizeof(Ov013TextBuffer));
    func_ov013_02185424(menu, menu->textBuffer);
    func_0205d5d0(&menu->widgetGroup, 0, menu->textBuffer, 1, 0);
}

extern "C" void func_ov013_02186c1c(Ov013Menu* menu)
{
    memset(menu->textBuffer, 0, sizeof(Ov013TextBuffer));
    func_ov013_02185be0(menu, menu->textBuffer);
    func_0205d5d0(&menu->widgetGroup, 3, menu->textBuffer, 1, 1);
}

extern "C" void func_ov013_02186c64(Ov013Menu* menu, unsigned int id, int flag)
{
    Ov013Widget* widget = func_0205d81c(&menu->widgetGroup, id);
    if (widget == 0)
        return;
    if (flag)
        widget->flags |= 0x40;
    else
        widget->flags &= ~0x40;
    if (id == 0)
        func_ov013_02186bd4(menu);
}
