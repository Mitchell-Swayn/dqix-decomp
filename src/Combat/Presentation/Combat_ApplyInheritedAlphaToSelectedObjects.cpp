#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *Combat_DispatchSelectionProcedure(int, int, unsigned char, int *);
extern "C" void *_ZN9GameState20GetGameObjectByIndexEi(void *, int);
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(void *, int, int);
// Original: arm9/ov025 @ 0x021E59B4; symbol: Combat_ApplyInheritedAlphaToSelectedObjects; size: 0x78.
// Dispatches combat selection into an index array and applies inherited alpha settings at settings +9 and +0xA to each found game object.
extern "C" int Combat_ApplyInheritedAlphaToSelectedObjects(const unsigned char *settings, int selection, int unused, int context) {
    void *gameState = _ZN9GameState11GetInstanceEv();
    int indices[8];
    int count = (int)Combat_DispatchSelectionProcedure(context, selection, settings[8], indices);
    for (int i = 0; i < count; ++i) {
        void *object = _ZN9GameState20GetGameObjectByIndexEi(gameState, indices[i]);
        if (object)
            _ZN8Object3D24TransitionInheritedAlphaEii(object, settings[9], *(const unsigned short *)(settings + 0xa));
    }
    return 1;
}
