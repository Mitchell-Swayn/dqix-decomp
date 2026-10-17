#include <globaldefs.h>
// func_0204950c: 0x0204950c–0x02049520, arm; 20 bytes
// Original: arm9/main @ 0x0204950C; symbol: func_0204950c; size: 0x14.
extern "C" void Object_ClearNestedOffset13CFlag40(int self) {
    int object = *(int*)(self + 0x13c);
        *(unsigned int*)(object + 0x20) &= ~0x40u;
}
