#include <globaldefs.h>
// func_0203ceb4: 0x0203ceb4–0x0203cec4, arm; 16 bytes
// Original: arm9/main @ 0x0203CEB4; symbol: func_0203ceb4; size: 0x10.
extern "C" void Object_SetUnsignedIntAtOffset5CMask4(int self) {
    *(unsigned int*)(self + 0x5c) |= 4;
}
