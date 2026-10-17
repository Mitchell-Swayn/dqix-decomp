#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02250bfc[];
extern "C" void func_ov031_02224f20(int value);
extern "C" int System_ResolveGlobalGroupEntry(int value);
// Original: arm9/ov031 @ 0x022247BC; symbol: func_ov031_022247bc; size: 0x30.
extern "C" void System_UpdateStateFromGlobalByte(void) {
    unsigned char *object = *(unsigned char **)data_ov031_02250bfc;
    func_ov031_02224f20(object[0x11d] == 2 ? 0 : 2);
    System_ResolveGlobalGroupEntry(1);
}
