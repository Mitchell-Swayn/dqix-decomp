#include <globaldefs.h>
ARM
struct GameState;
extern "C" GameState* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*, int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*, int);
// Original: arm9/ov017 @ 0x021BEF4C; symbol: func_ov017_021bef4c; size: 0x38.
extern "C" void GameState_UpdateTextCountAndClearEmbeddedObject() {
    GameState* state = _ZN9GameState11GetInstanceEv();
    void* object = (void*)TextContext_GetSharedInstance();
    TextWindow_AdvanceTextForRequestedTicks(object, (int)_ZNK9GameState12GetTickCountEv(state));
    TextWindow_RenderAndTransferDisplayBuffers(object, 0);
}
