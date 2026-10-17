#include <globaldefs.h>
ARM
struct GameState; struct GameResources; struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void Object_ResetSelectionAndApplyConfiguredMode(State* p,int flag);
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(int,unsigned);
extern "C" bool TestNonnegativeIdentifierWithByteOverride(char* p);
extern "C" int ReadSignedHalfwordAtOffsetB8(void*);
extern "C" char data_02109bf4[];
// Original: arm9/ov008 @ 0x021868A8; symbol: func_ov008_021868a8; size: 0xBC.
extern "C" void Graphics_UpdateSelectionFadeOut(unsigned char *self) {
    GameResources *resources = GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv());
    if (self[0xb11] == 0) {
        if (*(int*)(self + 0xb24) == 0) {
            _Z13SetBrightnessP13GameResourcesii(resources,-16,15);
            if (!self[0xb13] && ReadSignedHalfwordAtOffsetB8(data_02109bf4) != 41)
                DispatchObjectStateOneOrTwoUnlessFlag4((int)data_02109bf4,15);
        } else _Z16SetSubBrightnessP13GameResourcesii(resources,-16,15);
        self[0xb11]++;
    } else if (self[0xb11] == 1) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources(resources)) return;
        if (TestNonnegativeIdentifierWithByteOverride(data_02109bf4)) return;
        Object_ResetSelectionAndApplyConfiguredMode((State*)(self + 0x130),1);
        self[0xb10] = 14;
        self[0xb11] = 0;
    }
}
