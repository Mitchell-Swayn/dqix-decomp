#include "MenuText.h"

extern "C" {
void func_0205c96c(void*, int);
void func_0205d1e0(Ov013WidgetGroup*);
void func_0205d228(Ov013WidgetGroup*);
void func_0205da88(Ov013WidgetGroup*, int, int, int);
void func_0205d274(Ov013WidgetGroup*);
void func_ov013_02186cac(Ov013Menu*);
void func_ov013_02186db4(Ov013Menu*);
}

// Refresh the active menu, including its cursor and secondary display.
extern "C" void func_ov013_02184a58(Ov013Menu* menu)
{
    int state = menu->state[4];
    if (menu->state[4] == 0 || menu->state[4] == 5 || menu->state[4] == 6)
        return;
    if (menu->state[4] == 3 || menu->state[4] == 4)
        func_0205c96c(menu->unknown3D4, 0);
    func_0205d1e0(&menu->widgetGroup);
    func_0205d228(&menu->widgetGroup);
    if (menu->borrowedGroup)
        func_0205da88(&menu->widgetGroup, 0, 2, 0);
    else
        func_0205da88(&menu->widgetGroup, 1, 2, 1);
    func_0205d274(&menu->widgetGroup);
    func_ov013_02186cac(menu);
    func_ov013_02186db4(menu);
}
