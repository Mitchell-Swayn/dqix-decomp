#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov000 @ 0x0216FE48; symbol: func_ov000_0216fe48; size: 0x2C.
extern "C" void BattleText_ResetSelectiveStringLoader(void *object) {
    *(int *)object = -1;
    *(int *)((char *)object + 0x84) = 0;
    *(unsigned char *)((char *)object + 0xa0) = 0;
    *(unsigned char *)((char *)object + 0xa1) = 0;
    memset((char *)object + 0x88, 0, 0x18);
}
