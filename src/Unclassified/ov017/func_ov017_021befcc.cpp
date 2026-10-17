#include <globaldefs.h>
ARM
extern "C" void func_ov017_021bef84(void *);

// Original: arm9/ov017 @ 0x021BEFCC; symbol: func_ov017_021befcc; size: 0x18.
extern "C" int func_ov017_021befcc(void *object) {
    func_ov017_021bef84(object);
    ((unsigned char *)object)[1] = 1;
    return 1;
}
