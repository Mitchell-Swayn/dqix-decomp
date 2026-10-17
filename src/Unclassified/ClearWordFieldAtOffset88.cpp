#include <globaldefs.h>
// func_020bd908: 0x020bd908–0x020bd914, arm; 12 bytes
// Original: arm9/main @ 0x020BD908; symbol: func_020bd908; size: 0xC.
extern "C" void ClearWordFieldAtOffset88(unsigned int ignored0, unsigned int ignored1, int self) {
    *(unsigned int*)(self + 0x88) = 0;
}
