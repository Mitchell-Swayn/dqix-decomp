#include <globaldefs.h>
ARM
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned int);
extern "C" void SetStateWithTransitionCallbacks(int);
extern "C" int func_ov031_022394b4(void);
extern "C" int func_ov031_02239550(void);
extern "C" unsigned char data_ov031_02290d18[];
// Original: arm9/ov031 @ 0x02239448; symbol: func_ov031_02239448; size: 0x6C.
extern "C" void UpdateContextFromStateOrGlobalObject(void *state) {
    unsigned short value = *(unsigned short *)((char *)state + 2);
    if (value != 0) {
        SetSharedObjectWord54UnlessStateNineOrTen(value);
        SetStateWithTransitionCallbacks(9);
        return;
    }
    unsigned char *object = *(unsigned char **)(data_ov031_02290d18 + 4);
    if (*(int *)(object + 0x1000 + 0x3ac) != 0) {
        if (func_ov031_022394b4() == 0) SetStateWithTransitionCallbacks(9);
        return;
    }
    if (func_ov031_02239550() == 0) SetStateWithTransitionCallbacks(9);
}
