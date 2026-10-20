#include <globaldefs.h>
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState20GetGameObjectByIndexEi(void *, int);
// Original: arm9/ov017 @ 0x021A2738; symbol: func_ov017_021a2738; size: 0x54.
extern "C" void *Ov017_FindGameObjectByHalfwordId(int unused, int id) {
    if (id < 0) return 0;
    void *state = _ZN9GameState11GetInstanceEv();
    int i;
    for (i = 0; i < 12; i++) {
        void *object = _ZN9GameState20GetGameObjectByIndexEi(state, i + 7);
        if (object != 0 && id == *(short *)((char *)object + 2)) return object;
    }
    return 0;
}
