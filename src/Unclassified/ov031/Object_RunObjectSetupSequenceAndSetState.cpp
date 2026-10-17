#include <globaldefs.h>
extern "C" void func_ov031_02208c14(void*, unsigned, unsigned);
extern "C" void System_BuildAndCopyThreeContextRecords(void*);
extern "C" void func_ov031_02207b44(void*, unsigned, unsigned);
extern "C" void func_ov031_02208f50(void*);
// Original: arm9/ov031 @ 0x0220911C; symbol: func_ov031_0220911c; size: 0x3C.
extern "C" void Object_RunObjectSetupSequenceAndSetState(void* object, unsigned a, unsigned b) {
    func_ov031_02208c14(object, a, *(unsigned*)((char*)object + 0x81c));
    System_BuildAndCopyThreeContextRecords(object);
    func_ov031_02207b44(object, 0, 0);
    func_ov031_02208f50(object);
    *((unsigned char*)object + 0x455) = 5;
}
