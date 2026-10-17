#include <globaldefs.h>
ARM
extern unsigned char data_ov001_02165880[];
extern "C" int func_ov001_02158ab8(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x0215D168; symbol: func_ov001_0215d168; size: 0x34.
extern "C" int Grotto_SetNestedSecondWordFromGlobalPredicate(void *arg) {
    void *object = *(void **)(data_ov001_02165880 + 0x24);
    int value = func_ov001_02158ab8(object) == 0;
    SetNestedSecondWordForTypeThree(arg, value);
    return 1;
}
