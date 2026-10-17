#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameState_GetIndexList(void *);
extern "C" unsigned char ReadGlobalElementI(unsigned int);
extern "C" short CountPositiveSignedByteQuantities(void *, int);

// Original: arm9/ov003 @ 0x02175F90; symbol: func_ov003_02175f90; size: 0x44.
extern "C" short func_ov003_02175f90(void *state) {
    void *indices = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    short index = (short)(*(short *)((unsigned char *)state + 0x1012) - 0x11e);
    unsigned char quantity = ReadGlobalElementI(index);
    return CountPositiveSignedByteQuantities((unsigned char *)indices + 0x1d4, quantity);
}
