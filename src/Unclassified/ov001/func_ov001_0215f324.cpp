#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x0215F324; symbol: func_ov001_0215f324; size: 0x20.
extern "C" int func_ov001_0215f324(void *p) {
    unsigned int value = *(unsigned short *)((unsigned char *)ReadGlobalValueAt020FB3F0() + 2);
    SetNestedSecondWordForTypeThree(p, value);
    return 1;
}
