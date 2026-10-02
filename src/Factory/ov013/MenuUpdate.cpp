#include "MenuText.h"
#include <GameState/GameState.h>

extern "C" {
unsigned char* func_020421a0();
Ov013Widget* func_0205d888(Ov013WidgetGroup*);
int func_0204c7cc(Ov013Widget*);
void func_0205bc24(void*, int);
int func_0205d0e0(Ov013WidgetGroup*, unsigned int);
void func_0205c904(void*, unsigned int);
void func_0205a330(Ov013TranslationGroup*, unsigned int);
void func_0205bc10(void*);
void func_0205ba68(void*, int, int, int);
void func_0205bacc(void*, int);
void func_0205bcdc(void*, int);
void func_0205bb04(void*, int);
void func_0205deb4(Ov013WidgetGroup*, unsigned char, unsigned char);
void func_ov013_02184d80(Ov013Menu*);
void func_ov013_02186160(Ov013Menu*);
void func_ov013_0218678c(Ov013Menu*);
void func_ov013_021864f0(Ov013Menu*);
void func_ov013_0218683c(Ov013Menu*);
void func_ov013_02186590(Ov013Menu*);
void func_ov013_021846a0(Ov013Menu*);
}

// The original fallback retained this entry even without a static caller.
#pragma force_active on
extern "C" unsigned char func_ov013_021847c4(Ov013Menu* menu, unsigned int translationStep)
{
    menu->translationStep = translationStep;
    GameState* game = GameState::GetInstance();
    menu->tickCount = game->GetTickCount();
    Ov013Widget* widget = func_0205d888(&menu->widgetGroup);
    if (widget && func_0204c7cc(widget) && !(widget->flags & 2))
        func_0205bc24(&menu->widgetGroup.primary, -1);
    menu->mode = func_0205d0e0(&menu->widgetGroup, menu->tickCount);
    func_0205c904(menu->unknown3D4, menu->tickCount);
    Ov013TranslationGroup* translations = *(Ov013TranslationGroup**)(func_020421a0() + 0x2e0);
    if (translations)
        func_0205a330(translations, game->GetTickCount());
    if (menu->state[7]) {
        if (menu->borrowedGroup)
            func_0205bc10(&menu->widgetGroup.primary);
        if (menu->state[4] == 1) {
            menu->widgetGroup.state[1] = 0;
            menu->widgetGroup.primary.words[1] = 1;
            menu->widgetGroup.secondary.words[1] = 1;
            func_0205ba68(&menu->widgetGroup.primary, 1, 6, 0);
            func_0205ba68(&menu->widgetGroup.secondary, 1, 6, 0);
            func_0205bacc(&menu->widgetGroup.primary, 6);
            func_0205bacc(&menu->widgetGroup.secondary, 6);
            int selection = menu->primarySelection;
            func_0205bcdc(&menu->widgetGroup.primary, selection);
            func_0205bb04(&menu->widgetGroup.secondary, selection);
            func_ov013_02186bd4(menu);
        }
        if (menu->state[4] == 3 && menu->borrowedGroup) {
            menu->widgetGroup.state[1] = 3;
            menu->widgetGroup.primary.words[1] = 1;
            menu->widgetGroup.secondary.words[1] = 1;
            func_0205ba68(&menu->widgetGroup.primary, 1, 2, 0);
            func_0205ba68(&menu->widgetGroup.secondary, 1, 2, 0);
            func_0205bacc(&menu->widgetGroup.primary, 2);
            func_0205bacc(&menu->widgetGroup.secondary, 2);
            func_0205bcdc(&menu->widgetGroup.primary, 0);
            func_0205bb04(&menu->widgetGroup.secondary, 0);
        }
        menu->state[7] = 0;
        return menu->state[4];
    }
    switch (menu->state[4]) {
    case 0: func_ov013_02184d80(menu); break;
    case 1: func_ov013_02186160(menu); break;
    case 2:
        if (menu->borrowedGroup) func_ov013_0218678c(menu);
        else func_ov013_021864f0(menu);
        break;
    case 3:
    case 4:
        if (menu->borrowedGroup) func_ov013_0218683c(menu);
        else func_ov013_02186590(menu);
        break;
    case 5: func_ov013_021846a0(menu); break;
    }
    for (int i = 0; i < 4; ++i)
        func_0205deb4(&menu->widgetGroup, (unsigned char)i, menu->state[i]);
    menu->state[7] = menu->state[4] != menu->state[5];
    menu->state[5] = menu->state[4];
    return menu->state[4];
}
