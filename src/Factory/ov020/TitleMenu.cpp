#include "GameState/GameState.h"
#include "TitleController.h"

struct TitleUIObject;
struct TitleUIContext {
    unsigned char unknown_000[0x2e0];
    TitleUIObject* activeObject;
};
struct TitleButtonState {
    unsigned short current;
    unsigned short previous;
};

extern "C" {
void func_0205ba68(TitleSelectionGrid*, int, int, unsigned char);
void func_0205bacc(TitleSelectionGrid*, int);
TitleUIContext* func_020421a0();
void func_0205c77c(TitleMenuInput*, unsigned char);
void func_0205cd28(TitleMenu*);
void func_0205c904(TitleMenu*, int);
void func_0205a330(TitleUIObject*, int);
int func_0205cde8(TitleMenu*);
int func_02012444(TitleButtonState*, unsigned int);
int func_0205cecc(TitleMenu*);
int func_0205cb64(TitleMenu*);
unsigned char func_0200fb9c(GameState*);
void func_0200fb94(GameState*, unsigned char);
int func_020ab9c0(int);
void func_0205c96c(TitleMenu*, int);
extern TitleButtonState data_02114e30;

// The menu index maps to a GameState scene selector, including debug entries.
extern const int data_ov020_0218d974[7] = {4, 0, 2, 100, 6, 1, 3};
extern const int data_ov020_0218d990[8] = {4, 0, 5, 2, 100, 6, 1, 3};

// func_ov020_0218b710 indexes each label with a 32-byte stride.
extern const char data_ov020_0218d9b0[7][32] = {
    "Debug", "Start", "Create", "Delete", "Title", "Chara Viewer", "Movie"
};
extern const char data_ov020_0218da90[8][32] = {
    "Debug", "Start", "On the way", "Create", "Delete", "Title", "Chara Viewer", "Movie"
};
}

extern "C" void func_ov020_0218c7f0(TitleMenu* menu, int columns, int rows) {
    func_0205ba68(&menu->primaryGrid, columns, rows, 0);
    func_0205ba68(&menu->secondaryGrid, columns, rows, 0);
    int count = columns * rows;
    func_0205bacc(&menu->primaryGrid, count);
    func_0205bacc(&menu->secondaryGrid, count);
}

extern "C" void func_ov020_0218c840(TitleTransitionController* state) {
    GameState* game = GameState::GetInstance();
    TitleUIContext* ui = func_020421a0();
    if (state->frameCounter == 0) {
        state->menu.updateEnabled = 1;
        state->menu.inputEnabled = 1;
        func_0205c77c(&state->menu.input, 1);
        func_0205cd28(&state->menu);
    }
    func_0205c904(&state->menu, 1);
    if (ui->activeObject)
        func_0205a330(ui->activeObject, 1);
    if (func_0205cde8(&state->menu)) {
        if (state->frameCounter > 5) {
            volatile unsigned int* display = (volatile unsigned int*)0x04000000;
            *display = (*display & ~0x1f00) | 0x1300;
        }
        int buttons = func_02012444(&data_02114e30, 0x401);
        int touchSelected = func_0205cecc(&state->menu) >= 0;
        if (buttons | touchSelected) {
            int index = func_0205cb64(&state->menu);
            if (func_0200fb9c(game) == 6)
                return;
            if (func_020ab9c0(1) == 4) {
                func_0200fb94(game, data_ov020_0218d990[index]);
                state->state = -1;
                state->frameCounter = -1;
                return;
            } else {
                func_0200fb94(game, data_ov020_0218d974[index]);
                state->state = -1;
                state->frameCounter = -1;
                return;
            }
        }
    }
    func_0205c96c(&state->menu, 0);
}
