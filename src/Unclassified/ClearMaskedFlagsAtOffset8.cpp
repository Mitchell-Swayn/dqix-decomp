#include <globaldefs.h>
// func_0203b520: 0x0203b520–0x0203b534, arm; 20 bytes
// Original: arm9/main @ 0x0203B520; symbol: func_0203b520; size: 0x14.
extern "C" void ClearMaskedFlagsAtOffset8(int self, unsigned int mask) {
    *(unsigned int*)(self + 8) &= ~mask;
}
