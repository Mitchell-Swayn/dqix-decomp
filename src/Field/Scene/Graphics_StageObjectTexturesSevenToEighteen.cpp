#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" void* _ZN7Model3D7GetTEX0Ev(void*);
extern "C" void _Z23StageTexFilePaletteDataPV8NSBXXTexb(void*, bool);
extern "C" void _Z21StageTexFileImageDataPV8NSBXXTexb(void*, bool);
// Original: arm9/ov017 @ 0x021A2840; symbol: func_ov017_021a2840; size: 0x68.
extern "C" void Graphics_StageObjectTexturesSevenToEighteen(void) {
    void* game = _ZN9GameState11GetInstanceEv();
    for (int i = 0; i < 12; ++i) {
        void* object = _ZN9GameState20GetGameObjectByIndexEi(game, i + 7);
        if (object == 0) continue;
        void* model = *(void**)((char*)object + 8);
        if (model == 0) continue;
        void* texture = _ZN7Model3D7GetTEX0Ev(model);
        if (texture == 0) continue;
        _Z23StageTexFilePaletteDataPV8NSBXXTexb(texture, false);
        _Z21StageTexFileImageDataPV8NSBXXTexb(texture, false);
    }
}
