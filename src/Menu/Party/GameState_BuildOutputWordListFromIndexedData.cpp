#include <globaldefs.h>
ARM
// Original: arm9/ov002 @ 0x02157424; symbol: func_ov002_02157424; size: 0x5C.
extern "C" void GameState_BuildOutputWordListFromIndexedData(void *p, int *out) {
    if (!out) return;
    for (int i = 0; i < 7; i++) out[i] = -1;
    out[0] = 4;
    int i = 0;
    while (i < *(volatile int *)((char *)p + 0x1c50)) {
        int value = *(int *)((char *)p + i * 4 + 0x1000 + 0xc54);
        i++;
        out[i] = value;
    }
}
