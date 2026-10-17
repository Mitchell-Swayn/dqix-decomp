#include <globaldefs.h>
ARM
extern "C" void func_ov017_021b88d0(void *, unsigned, unsigned);
// Original: arm9/ov017 @ 0x021CA2D8; symbol: func_ov017_021ca2d8; size: 0x20.
extern "C" void func_ov017_021ca2d8(void *unused0, unsigned char *fields, void *unused2, char *base) {
    func_ov017_021b88d0(*(void **)(base + 0x3718), *(unsigned short *)(fields + 4), *(unsigned short *)(fields + 6));
}
