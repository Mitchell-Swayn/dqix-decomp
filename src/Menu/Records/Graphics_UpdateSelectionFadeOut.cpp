#include <globaldefs.h>
ARM
struct GameState; struct GameResources; struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void Window_PopCanvasesAndResetSelection(State* p,int flag);
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(int,unsigned);
extern "C" bool Bgm_IsTemporarySequencePendingOrPlaying(char* p);
extern "C" int Bgm_GetPrimarySequenceId(void*);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov008 @ 0x021868A8; symbol: func_ov008_021868a8; size: 0xBC.
extern "C" void Graphics_UpdateSelectionFadeOut(unsigned char *self) {
    GameResources *resources = GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv());
    if (self[0xb11] == 0) {
        if (*(int*)(self + 0xb24) == 0) {
            _Z13SetBrightnessP13GameResourcesii(resources,-16,15);
            if (!self[0xb13] && Bgm_GetPrimarySequenceId(Main_UnknownRoleZeroInitializedStorage_Variant2) != 41)
                Bgm_StopActiveSequenceUnlessBlocked((int)Main_UnknownRoleZeroInitializedStorage_Variant2,15);
        } else _Z16SetSubBrightnessP13GameResourcesii(resources,-16,15);
        self[0xb11]++;
    } else if (self[0xb11] == 1) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources(resources)) return;
        if (Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2)) return;
        Window_PopCanvasesAndResetSelection((State*)(self + 0x130),1);
        self[0xb10] = 14;
        self[0xb11] = 0;
    }
}
