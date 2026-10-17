#include <globaldefs.h>
// func_020493dc: 0x020493dc–0x020493ec, arm; 16 bytes
// Original: arm9/main @ 0x020493DC; symbol: func_020493dc; size: 0x10.
extern "C" void Object_WriteNestedOffset13CByte1E(int self, unsigned char value) {
    int object = *(int*)(self + 0x13c);
        if (object != 0) {
            *(unsigned char*)(object + 0x1e) = value;
        }
}
