#include <globaldefs.h>
ARM
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned int);
extern "C" int func_ov031_02239550(void);
extern "C" void SetStateWithTransitionCallbacks(int);
// Original: arm9/ov031 @ 0x02239518; symbol: func_ov031_02239518; size: 0x38.
extern "C" void UpdateContextAndEnterStateNine(void *state) {
    unsigned short value = *(unsigned short *)((char *)state + 2);
    if (value != 0) {
        SetSharedObjectWord54UnlessStateNineOrTen(value);
        SetStateWithTransitionCallbacks(9);
        return;
    }
    if (func_ov031_02239550() == 0) SetStateWithTransitionCallbacks(9);
}
