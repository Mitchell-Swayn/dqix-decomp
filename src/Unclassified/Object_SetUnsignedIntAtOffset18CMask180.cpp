#include <globaldefs.h>
// func_02054224: 0x02054224–0x02054234, arm; 16 bytes
// Original: arm9/main @ 0x02054224; symbol: func_02054224; size: 0x10.
extern "C" void Object_SetUnsignedIntAtOffset18CMask180(int self) {
    *(unsigned int*)(self + 0x18c) |= 0x180;
}
