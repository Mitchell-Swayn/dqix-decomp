#include <globaldefs.h>
ARM
extern "C" void func_ov001_021575ec(void *);
// Original: arm9/ov001 @ 0x02158324; symbol: func_ov001_02158324; size: 0x14.
extern "C" int Object_InvokeHelperOnField15C(void *unused, void *object) {
    func_ov001_021575ec((unsigned char *)object + 0x15c);
    return 0;
}
