#include <globaldefs.h>
ARM
extern "C" int func_ov031_02214520(unsigned);
extern "C" unsigned char func_ov031_02214afc(unsigned);
extern "C" int func_ov031_02214d38(void*);
// Original: arm9/ov031 @ 0x02215150; symbol: func_ov031_02215150; size: 0x60.
extern "C" int Overlay_DeriveNextResultFromPackedMode(unsigned char* self) {
    if (*(unsigned short*)(self + 0xd16) != 0 && func_ov031_02214520(2) != 0) {
        self[0xd11] = (unsigned char)func_ov031_02214afc(0);
        return 5;
    }
    unsigned nibble = ((unsigned)self[0xd0b] << 24) >> 28;
    if (nibble >= 1) return 6;
    return func_ov031_02214d38(self);
}
