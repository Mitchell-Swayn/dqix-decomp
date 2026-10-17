#include <globaldefs.h>
ARM
extern "C" void func_ov017_0219949c(unsigned arg3, unsigned arg0, unsigned char field4, unsigned char field5, int field7);
extern "C" void func_ov017_02199578(unsigned arg3, unsigned arg0, unsigned char field4, unsigned char field5, int field7);
// Original: arm9/ov017 @ 0x021D08CC; symbol: func_ov017_021d08cc; size: 0x58.
extern "C" void Script_DispatchDescriptorByMode(unsigned arg0, const unsigned char *descriptor, void *arg2, unsigned arg3) {
    unsigned mode = descriptor[6];
    if (mode == 0) {
        func_ov017_0219949c(arg3, arg0, descriptor[4], descriptor[5], (signed char)descriptor[7]);
    } else if (mode == 1) {
        func_ov017_02199578(arg3, arg0, descriptor[4], descriptor[5], (signed char)descriptor[7]);
    }
}
