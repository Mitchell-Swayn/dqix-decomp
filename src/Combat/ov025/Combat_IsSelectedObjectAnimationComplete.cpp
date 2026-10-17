#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" bool _ZNK8Object3D19HasAnimationStoppedEv(void*);
extern "C" bool _ZNK8Object3D22HasAnimationReachedEndEv(void*);
extern "C" void DispatchCombatSelectionProcedure(void*,void*,int,void*);
// Original: arm9/ov025 @ 0x021E6F44; symbol: func_ov025_021e6f44; size: 0xB4.
extern "C" int Combat_IsSelectedObjectAnimationComplete(void *unused, void *input, void *unused2, void *context) {
    void *state = _ZN9GameState11GetInstanceEv();
    int selection[12];
    DispatchCombatSelectionProcedure(context,input,23,selection);
    int index = selection[0];
    char *object = _ZN9GameState20GetGameObjectByIndexEi(state,index);
    if (!object) return 1;
    int party;
    if (index >= 0 && index <= 3) party = 1;
    else party = 0;
    if (party) {
        if (*(int*)(object+0x24) < 0xb33) return 0;
    } else {
        if (!_ZNK8Object3D19HasAnimationStoppedEv(object)) {
            if (!_ZNK8Object3D22HasAnimationReachedEndEv(object)) return 0;
        }
    }
    return 1;
}
