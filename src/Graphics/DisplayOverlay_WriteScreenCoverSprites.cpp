#pragma opt_lifetimes off
#pragma opt_common_subs off
#include <globaldefs.h>
extern "C" void* DisplayOverlay_GetScreenOAMBuffer(void*, unsigned);
// Original: arm9/main @ 0x020DB6E4; symbol: func_020db6e4; size: 0x84.
extern "C" ARM void DisplayOverlay_WriteScreenCoverSprites(void* owner, unsigned short value) {
    unsigned char* storage = (unsigned char*)DisplayOverlay_GetScreenOAMBuffer(owner, *(unsigned char*)((unsigned char*)owner + 0x3c));
    value |= 0xf800;
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 4; ++column) {
            int index = column + row * 4 + 0x10;
            *(unsigned*)(storage + index * 8) = (((row << 6) & 0xff) | 0xc0000000 | ((((unsigned)column << 0x1d) >> 7)));
            *(unsigned short*)(storage + index * 8 + 4) = value;
            *(unsigned short*)(storage + index * 8 + 4) = (unsigned short)((*(unsigned short*)(storage + index * 8 + 4) & ~0xc00) | 0x800);
        }
    }
}
