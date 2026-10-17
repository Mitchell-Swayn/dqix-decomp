#include <globaldefs.h>
// func_0209c830: 0x0209c830–0x0209c840, arm; 16 bytes
// Original: arm9/main @ 0x0209C830; symbol: func_0209c830; size: 0x10.
extern "C" void Object_SetUnsignedShortAtOffsetCEAndSetUnsignedCharAtOffsetC9To1(int self, unsigned short value) {
    *(unsigned short*)(self + 0xce) = value;
        *(unsigned char*)(self + 0xc9) = 1;
}
