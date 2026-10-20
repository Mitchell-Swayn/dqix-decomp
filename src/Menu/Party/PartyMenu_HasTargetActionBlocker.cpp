#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
// Original: arm9/ov002 @ 0x02154B94; symbol: func_ov002_02154b94; size: 0x38.
extern "C" bool PartyMenu_HasTargetActionBlocker(int ignored, int value) {
    void *object = GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(), value);
    if (object == 0) return false;
    return *(unsigned short *)((unsigned char *)object + 0x1B2) != 0;
}
