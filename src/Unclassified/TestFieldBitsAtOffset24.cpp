#include <globaldefs.h>
// func_020de13c: 0x020de13c–0x020de148, arm; 12 bytes
// Original: arm9/main @ 0x020DE13C; symbol: func_020de13c; size: 0xC.
extern "C" unsigned char TestFieldBitsAtOffset24(int self) {
    return *(unsigned char*)(self + 0x24) & 2;
}
