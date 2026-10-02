#include "GameState/GameState.h"

// The pen PAC loader builds 0x18-byte animation records, found by the
// identifier at +8. Names describe the operations observed in this overlay.
struct PenAnimation {
    unsigned char unknown_00[4];
    short x;
    short y;
    unsigned short identifier;
    unsigned char unknown_0a[0x14 - 0x0a];
    unsigned char layer;
    unsigned char flags;
    unsigned char unknown_16[2];
};

struct PenAnimationTable {
    PenAnimation* entries;
    unsigned short count;
    unsigned short unknown_06;
};

// Initialized at 0205a444; +3c points to the animation table. The opaque
// regions hold resource state whose fields are not used by these helpers.
struct PenRenderer {
    unsigned char unknown_00[0x3c];
    PenAnimationTable* animations;
    unsigned char unknown_40[0x50 - 0x40];
    unsigned char enabled;
    unsigned char padding_51[3];
};

// The large overlay routine initializes the embedded renderer, assigns its
// animation table to the embedded table at +2d8, and loads data/ani/pen.pac.
struct Overlay19Scene {
    unsigned char unknown_00[0x4c];
    unsigned int flags;
    unsigned int unknown_50;
    PenRenderer pen;
};

struct ButtonState {
    unsigned short current;
    unsigned short previous;
};

struct TouchState {
    unsigned char unknown_00[0x55];
    unsigned char active;
};

extern "C" void func_0205a370(PenAnimationTable*, unsigned char);
extern "C" PenAnimation* func_0205a3d0(PenAnimationTable*, unsigned char);
extern "C" void func_0205a330(PenAnimationTable*, unsigned int);
extern "C" void func_0205a42c(PenAnimationTable*, unsigned char, unsigned char);
extern "C" void func_0205ae8c(PenRenderer*);
extern "C" int func_02012444(ButtonState*, unsigned int);
extern "C" void func_0205eaa0(void*, int, int);

extern ButtonState data_02114e30;
extern TouchState data_02114e54;
extern char data_02108760[];

extern "C" void func_ov019_0218c178(Overlay19Scene* scene)
{
    GameState* game = GameState::GetInstance();
    if (scene->flags & 1) {
        PenAnimationTable* table = scene->pen.animations;
        if (table) {
            func_0205a370(table, 1);
            PenAnimation* animation = func_0205a3d0(table, 1);
            if (animation) animation->flags |= 8;
            func_0205a330(table, game->GetTickCount());
            animation = func_0205a3d0(table, 1);
            if (animation) {
                animation->x = 215;
                animation->y = 150;
            }
            func_0205a42c(table, 1, 0x24);
        }
        func_0205ae8c(&scene->pen);
    } else {
        if (scene->pen.animations) {
            PenAnimation* animation = func_0205a3d0(scene->pen.animations, 1);
            if (animation) animation->flags &= ~8;
        }
    }
}

extern "C" int func_ov019_0218c240(Overlay19Scene*)
{
    if (!func_02012444(&data_02114e30, 0x7f3) && !data_02114e54.active)
        return 0;
    func_0205eaa0(data_02108760, 1, 0);
    return 1;
}
