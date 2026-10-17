#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void SetAngleAndCacheTrig(void*,unsigned);
extern "C" unsigned data_02104300;
// Original: arm9/main @ 0x0202F0E0; symbol: func_0202f0e0; size: 0xC4.
extern "C" void Graphics_AdvanceTimedAngleTransition(char *self) {
    unsigned delta;
    int current;
    if (!*(unsigned*)(self + 0x1f4)) return;
    delta = _ZNK9GameState21GetEffectiveDeltaTimeEv(_ZN9GameState11GetInstanceEv());
    current = *(int*)(self + 0x58);
    int angle;
    if (delta >= *(unsigned*)(self + 0x1f4)) {
        *(unsigned*)(self + 0x1f4) = 0;
        angle = *(int*)(self + 0x1f0);
    } else {
        float start = (float)current;
        float difference = (float)(*(int*)(self + 0x1f0) - current);
        angle = (int)(start + difference * ((float)delta / (float)*(unsigned*)(self + 0x1f4)));
        *(unsigned*)(self + 0x1f4) -= delta;
        ++data_02104300;
    }
    SetAngleAndCacheTrig(self,angle);
}
