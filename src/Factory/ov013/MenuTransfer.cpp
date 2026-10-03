#include "MenuText.h"
#include <GameState/GameState.h>

extern "C" {
void* func_020421a0();
void func_0204359c(void*, unsigned int);
void func_020439b0(void*, int);
void func_0205d2bc(Ov013WidgetGroup*);
void func_0205cb60(void*);
unsigned char* func_02053c6c(void*);
unsigned char func_020dd11c(unsigned char, unsigned char);
}

// Only the owner records consumed here are known.
struct Ov013Owner {
    unsigned char unknown00[0x130];
    unsigned short* ordinaryCursor;
    unsigned short* settings;
    unsigned short* borrowedCursor;
};

#pragma force_active on
extern "C" void func_ov013_02184aec(Ov013Menu* menu)
{
    if (menu->state[4] == 0 || menu->state[4] == 5 || menu->state[4] == 6)
        return;
    GameState* game = GameState::GetInstance();
    void* context = func_020421a0();
    func_0204359c(context, game->GetTickCount());
    func_020439b0(context, 0);
    func_0205d2bc(&menu->widgetGroup);
    func_0205cb60(menu->unknown3D4);
}

extern "C" void func_ov013_02184b4c(Ov013Menu* menu, Ov013Owner* owner)
{
    if (!owner)
        return;
    unsigned char* values = func_02053c6c(owner);
    menu->unknown6A4 = (int)owner->settings;
    menu->unknown668 = menu->unknown66C = *(unsigned short*)(values + 0x564);
    menu->flag6A8 = *(unsigned int*)(values + 0x950);
    menu->unknown6B0 = *(unsigned short*)((values + menu->flag6A8 * 2) + 0x16c);
    menu->unknown6B8 = (values + menu->flag6A8)[0x186];
    menu->cursorValues[1] = owner->settings[0x18];
    menu->cursorValues[3] = owner->settings[0x19];
    menu->cursorValues[4] = owner->settings[0x1a];
    menu->cursorValues[5] = owner->settings[0x1b];
    menu->cursorValues[6] = owner->settings[0x1c];
    if (menu->borrowedGroup) {
        menu->cursorValues[0] = owner->borrowedCursor[0];
        menu->cursorValues[2] = owner->borrowedCursor[1];
    } else {
        menu->cursorValues[0] = owner->ordinaryCursor[2];
        menu->cursorValues[2] = owner->ordinaryCursor[3];
    }
    if (menu->unknown6B8)
        menu->flag6B4 = 1;
    menu->unknown670 = 100;
    for (int i = 0; i < 5; ++i) {
        menu->flags6A9[i] = func_020dd11c(menu->flag6A8, (unsigned char)i);
        menu->enabled[i] = 0;
        menu->primaryValues[i] = (values + menu->flags6A9[i])[0x464];
    }
}

extern "C" void func_ov013_02184c8c(Ov013Menu* menu, void* owner)
{
    if (!owner || !menu->flags664[0])
        return;
    unsigned char* values = func_02053c6c(owner);
    *(unsigned short*)(values + 0x564) = menu->unknown66C;
    for (int i = 0; i < 5; ++i)
        (values + menu->flags6A9[i])[0x464] = menu->primaryValues[i] + menu->secondaryValues[i];
}

extern "C" void func_ov013_02184cf0(Ov013Menu* menu, SafeAllocator* parent)
{
    if (!parent)
        return;
    if (menu->borrowedGroup) {
        menu->stringAllocator.CreateTypeA(parent->Allocate(0xc00), 0xc00);
        return;
    }
    unsigned int size = parent->GetMaxPossibleAllocation();
    menu->allocator.CreateTypeA(parent->Allocate(size), size);
    menu->allocator.Reset();
    menu->stringAllocator.CreateTypeA(menu->allocator.Allocate(0xc00), 0xc00);
}
