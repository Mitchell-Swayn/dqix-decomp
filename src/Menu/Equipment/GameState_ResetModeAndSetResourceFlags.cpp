#include <globaldefs.h>
ARM
extern "C" void Window_PopCanvasesAndResetSelection(void*, int);
extern "C" void Grid_ChangeDisplayModeAndTransitionFlags(void*, int);
extern "C" void* GameResources_GetInstance();
extern "C" void* Field_GetSharedSubscreenInstance(void*);
// Original: arm9/ov005 @ 0x02159208; symbol: func_ov005_02159208; size: 0x6C.
extern "C" void GameState_ResetModeAndSetResourceFlags(unsigned char* state) {
    if (state[0x3ddc] != 0) return;
    Window_PopCanvasesAndResetSelection(state + 0xee4, 1);
    Grid_ChangeDisplayModeAndTransitionFlags(state, 6);
    state[0x3ddc] = 0;
    state[0x3dde] = 0;
    state[0x3ddf] = 0;
    unsigned char* resources = (unsigned char*)GameResources_GetInstance();
    unsigned char* object = *(unsigned char**)(resources + 0x3708);
    unsigned short* flags = (unsigned short*)((char*)Field_GetSharedSubscreenInstance(object) + 0x634);
    *flags |= 0x81;
}
