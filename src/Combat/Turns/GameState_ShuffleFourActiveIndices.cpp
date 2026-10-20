#include <globaldefs.h>
ARM
extern "C" void* _Z11GetBTRandomv();
extern "C" int _Z17NextRandomBetweenP6Randomii(void*, int, int);
// Original: arm9/ov000 @ 0x02163894; symbol: func_ov000_02163894; size: 0x94.
extern "C" void GameState_ShuffleFourActiveIndices(char *self) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        if (*(signed char *)(self + i + 0x773c) >= 0) ++count;
    }
    if (count <= 1) return;
    int rounds = _Z17NextRandomBetweenP6Randomii(_Z11GetBTRandomv(), 2, 10);
    for (int i = 1; i < rounds; ++i) {
        int index = i % count;
        signed char first = *(signed char *)(self + 0x773c);
        *(signed char *)(self + 0x773c) = *(signed char *)(self + 0x773c + index);
        *(signed char *)(self + 0x773c + index) = first;
    }
}
