#include <globaldefs.h>
ARM
extern "C" int func_ov031_0223e2c0(int, void *);
// Original: arm9/ov031 @ 0x0223C2D0; symbol: func_ov031_0223c2d0; size: 0x38.
extern "C" int func_ov031_0223c2d0(void *object, void *state) {
    short current = *(short *)((char *)state + 4);
    *(short *)((char *)state + 4) = current + 1;
    if (*(short *)((char *)state + 4) < *(unsigned short *)((char *)state + 6)) return (int)object;
    *((unsigned char *)state + 9) = 0;
    return func_ov031_0223e2c0(1, object);
}
