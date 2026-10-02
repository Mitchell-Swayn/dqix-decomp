#include "MenuText.h"

extern "C" {
Ov013Widget* func_0205d8c4(Ov013WidgetGroup*);
int func_0204c7e0(Ov013Widget*);
void func_0205a370(Ov013TranslationGroup*, unsigned int);
Ov013TranslationEntry* func_0205a3d0(Ov013TranslationGroup*, unsigned int);
void func_0205a330(Ov013TranslationGroup*, unsigned int);
void func_0205ae8c(Ov013Display*);
}

extern "C" void func_ov013_02186cac(Ov013Menu* menu)
{
    if (menu->display == 0)
        return;
    if (!(menu->cursorFlags & 1))
        return;
    Ov013Widget* widget = func_0205d8c4(&menu->widgetGroup);
    if (widget == 0 || !func_0204c7e0(widget))
        return;
    short x = widget->tileX * 8;
    short y = widget->tileY * 8;
    x += widget->offsetX;
    y += widget->offsetY;
    if (menu->state[4] == 3 || menu->state[4] == 4) {
        x -= 8;
    } else {
        x -= 8;
        y -= 2;
    }
    Ov013TranslationGroup* translations = menu->display->translations;
    if (translations == 0)
        return;
    func_0205a370(translations, menu->displayId);
    Ov013TranslationEntry* entry = func_0205a3d0(translations, menu->displayId);
    if (entry != 0)
        entry->flags |= 8;
    func_0205a330(translations, menu->translationStep);
    entry = func_0205a3d0(translations, menu->displayId);
    if (entry != 0) {
        entry->x = x;
        entry->y = y;
    }
    func_0205ae8c(menu->display);
}
