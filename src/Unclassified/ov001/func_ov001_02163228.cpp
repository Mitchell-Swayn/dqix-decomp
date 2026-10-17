#include <globaldefs.h>
ARM
extern "C" unsigned long long func_ov028_021d9748(void);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x02163228; symbol: func_ov001_02163228; size: 0x20.
extern "C" int func_ov001_02163228(void *p) {
    unsigned int value = (unsigned int)func_ov028_021d9748();
    SetNestedSecondWordForTypeThree(p, value);
    return 1;
}
