#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" unsigned int ReadWordFieldAtOffset954(unsigned int *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x021609C0; symbol: func_ov001_021609c0; size: 0x24.
extern "C" int func_ov001_021609c0(void *p) {
    unsigned int value = ReadWordFieldAtOffset954((unsigned int *)ReadWordFieldAtOffset1C());
    SetNestedSecondWordForTypeThree(p, value);
    return 1;
}
