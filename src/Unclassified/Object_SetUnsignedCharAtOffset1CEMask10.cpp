#include <globaldefs.h>
// func_02039dd8: 0x02039dd8–0x02039de8, arm; 16 bytes
// Original: arm9/main @ 0x02039DD8; symbol: func_02039dd8; size: 0x10.
extern "C" void Object_SetUnsignedCharAtOffset1CEMask10(int self) {
    *(unsigned char*)(self + 0x1ce) |= 0x10;
}
