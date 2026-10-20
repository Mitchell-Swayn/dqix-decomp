#include <globaldefs.h>
ARM
struct MapGameObject;
extern "C" MapGameObject *_ZN9GameState20GetUnknownGameObjectEv(void *);
// Original: arm9/ov017 @ 0x021D246C; symbol: func_ov017_021d246c; size: 0x38.
extern "C" void Field_ApplyInnRecoveryValueIfLeaderFlagged(void *unused, void *record, void *selector, unsigned char *base) {
    unsigned int flags = **(unsigned int **)((char *)_ZN9GameState20GetUnknownGameObjectEv(selector) + 0x130);
    if ((flags & 1) != 0) {
        unsigned int *entry = *(unsigned int **)(base + 0x3000 + 0xb0c);
        if (entry != 0) * (unsigned int *)((char *)entry + 0x60) = *(unsigned int *)((char *)record + 4);
    }
}
