#include <globaldefs.h>
ARM
struct GameState;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned char *GameState_FindIndexedObjectWithFlag400(GameState *, unsigned);
// Original: arm9/ov000 @ 0x02159D94; symbol: func_ov000_02159d94; size: 0x28.
extern "C" unsigned int GameState_GetIndexedObjectStateBits3And4(int ignored, unsigned index) {
    unsigned char *object = GameState_FindIndexedObjectWithFlag400((GameState *)_ZN9GameState11GetInstanceEv(), index);
    unsigned int value = *(unsigned int *)(*(unsigned int *)(object + 0x148) + 0x10);
    return (value << 27) >> 30;
}
