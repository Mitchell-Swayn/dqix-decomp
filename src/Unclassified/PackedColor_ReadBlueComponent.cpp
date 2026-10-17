#include <globaldefs.h>
// func_0204be90: 0x0204be90–0x0204bea0, arm; 16 bytes
// Original: arm9/main @ 0x0204BE90; symbol: func_0204be90; size: 0x10.
extern "C" int PackedColor_ReadBlueComponent(int self) {
    return (int)(*(unsigned short*)(self + 2) & 0x7c00) >> 10;
}
