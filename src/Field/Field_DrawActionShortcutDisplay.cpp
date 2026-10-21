#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#include "GameState/GameState.h"
typedef unsigned int undefined4;
typedef unsigned int uint;

struct WindowCanvasRecord {
    char pad[0xc4];
    unsigned char id;
    char rest[0x1b];
};
struct WindowCanvasOwner {
    char pad[0x98];
    void* ready;
    WindowCanvasRecord* records;
    char pad2[0x13];
    unsigned char count, stop;
};
struct TilemapOwner {
    unsigned int field0[5];
    unsigned short* tiles;
};

extern "C" GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState* state);
extern "C" void Graphics_PollQueuedZoneRenderPartAndRestoreVRAM(char* self);
extern "C" undefined4 GameObject_GetUnknownFieldActionSelectorAt260(int param_1);
extern "C" int GameObject_GetCurrentQueuedActionOrInvalid(signed char* p);
extern "C" void Ov017_AllocateVRAMStagingEntries(char* entries, int count, unsigned int size);
extern "C" void Window_ClearResourceBuffers(unsigned char* p);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void* object);
extern "C" void Window_FillCanvasRectanglesOnAlternateLayer(void* object, int first, int second, int third);
extern "C" uint GameResources_GetMaskedSecondaryFlags(int param_1, uint param_2);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner* self, unsigned id);
extern "C" void Tilemap_FillClippedRectangle(TilemapOwner* owner, unsigned int tile, short x, short y, short width, short height, unsigned int palette);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(unsigned char* state);
extern "C" void Window_ResetResourceTransfers(unsigned char* state);
extern "C" void Graphics_FreeVRAMStagingEntries(void* entries, int count);

// Original: arm9/ov017 @ 0x0219A18C; symbol: func_ov017_0219a18c; size: 0x1e4.
// Polls queued zone-render work for party objects 0-3, then if the field window is
// ready and the unknown object selector is -1, stages VRAM, fills the shortcut
// canvas for the protagonist action, and frees the staging entries.
extern "C" void Field_DrawActionShortcutDisplay(unsigned char* self) {
    for (int i = 0; i < 4; ++i) {
        GameObject* object = GameState_GetObjectWithFlag100(GameState::GetInstance(), i);
        if (object)
            Graphics_PollQueuedZoneRenderPartAndRestoreVRAM((char*)object);
    }

    if (!*(int*)(self + 0x4000 + 0x80) || !*(int*)(self + 0x4000 + 0x74))
        return;
    if (*(int*)(self + 0x4000 + 0x78) < 4)
        return;

    GameState* game = GameState::GetInstance();
    if (GameObject_GetUnknownFieldActionSelectorAt260((int)game->GetUnknownGameObject()) != -1)
        return;

    Ov017_AllocateVRAMStagingEntries((char*)(self + 0xb4 + 0x3c00), 2, 0x800);
    Window_ClearResourceBuffers(*(unsigned char**)(self + 0x3000 + 0xcb0));
    ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(*(void**)(self + 0x3000 + 0xcb0));
    Window_FillCanvasRectanglesOnAlternateLayer(*(void**)(self + 0x3000 + 0xcb0), 1, 2, 1);

    GameObject* protagonist = game->GetProtagonist();
    GameObject* object = GameState_GetObjectWithFlag100(game, GameState_ReadProtagonistObjectIndex(game));
    int drawn = 0;
    unsigned selector = GameObject_GetUnknownFieldActionSelectorAt260((int)protagonist);
    int queued = GameObject_GetCurrentQueuedActionOrInvalid((signed char*)object);
    int canvasId;
    switch (selector + 1) {
    case 1:
        drawn = 1;
        canvasId = 0;
        break;
    case 2:
        drawn = 1;
        canvasId = drawn;
        break;
    case 3:
        drawn = 1;
        canvasId = 2;
        break;
    case 4:
        drawn = 1;
        canvasId = 3;
        break;
    }

    if (drawn != 0 && queued >= 0) {
        WindowCanvasRecord* canvas = Window_FindActiveCanvasById(
            *(WindowCanvasOwner**)(self + 0x3000 + 0xcb0), (unsigned)canvasId);
        if (canvas) {
            Tilemap_FillClippedRectangle(
                (TilemapOwner*)(self + 0xb4 + 0x3c00),
                1,
                *(short*)((unsigned char*)canvas + 0xac),
                *(short*)((unsigned char*)canvas + 0xae),
                *(short*)((unsigned char*)canvas + 0xa8),
                *(short*)((unsigned char*)canvas + 0xaa),
                0xf);
        }
    }

    Graphics_ResetCountedThirtyTwoByteTransfers(*(unsigned char**)(self + 0x3000 + 0xcb0));
    if (GameResources_GetMaskedSecondaryFlags((int)self, 0x10000) == 0)
        Window_ResetResourceTransfers(*(unsigned char**)(self + 0x3000 + 0xcb0));
    Graphics_FreeVRAMStagingEntries(self + 0xb4 + 0x3c00, 2);
}
