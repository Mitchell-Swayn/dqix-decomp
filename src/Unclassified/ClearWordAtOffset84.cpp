#include <globaldefs.h>
// func_020bd8fc: 0x020bd8fc–0x020bd908, arm; 12 bytes
// Original: arm9/main @ 0x020BD8FC; symbol: func_020bd8fc; size: 0xC.
extern "C" void ClearWordAtOffset84(unsigned int ignored0, unsigned int ignored1, int self) {
    *(unsigned int*)(self + 0x84) = 0;
}
