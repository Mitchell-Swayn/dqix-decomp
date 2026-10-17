#include <globaldefs.h>
// func_020d805c: 0x020d805c–0x020d806c, arm; 16 bytes
// Original: arm9/main @ 0x020D805C; symbol: func_020d805c; size: 0x10.
extern "C" unsigned int Object_TestByte150BitSix(int self) {
    return ((unsigned int)*(unsigned char*)(self + 0x150) << 25) >> 31;
}
